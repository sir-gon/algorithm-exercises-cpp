FROM ubuntu:24.10 AS init

ENV WORKDIR=/app
WORKDIR ${WORKDIR}

RUN apt-get -y update && \
    apt-get -y install --no-install-recommends --no-install-suggests make && \
    rm -rf /var/lib/apt/lists/*

FROM init AS builder

# build tools
RUN apt-get -y update && \
    apt-get -y install --no-install-recommends --no-install-suggests build-essential cmake g++ make pkg-config && \
    rm -rf /var/lib/apt/lists/*

# vcpkg Package Manager
ADD https://github.com/microsoft/vcpkg/archive/refs/tags/2024.08.23.tar.gz vcpkg.tar.gz
RUN apt-get -y update && \
    apt-get -y install --no-install-recommends --no-install-suggests \
        ca-certificates curl git unzip zip && \
    rm -rf /var/lib/apt/lists/* && \
    mkdir /opt/vcpkg && \
    tar xf vcpkg.tar.gz --strip-components=1 -C /opt/vcpkg && \
    /opt/vcpkg/bootstrap-vcpkg.sh && \
    ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg && \
    rm -rf vcpkg.tar.gz && \
    vcpkg version
ENV VCPKG_ROOT=/opt/vcpkg

# sources
COPY ./src ${WORKDIR}/src
COPY ./vcpkg.json ${WORKDIR}/vcpkg.json
COPY ./CMakeLists.txt ${WORKDIR}/CMakeLists.txt
COPY ./CMakePresets.json ${WORKDIR}/CMakePresets.json
COPY ./Makefile ${WORKDIR}/

# dependencies
RUN vcpkg integrate install && \
    vcpkg install

LABEL vcpkg=enabled

# build
RUN ls -alhR && \
    mkdir build && \
    make build && \
    ls -alhR

CMD ["make", "build"]

FROM builder AS development

# CMD []

FROM init AS lint

RUN apt-get -y update && \
    apt-get -y install --no-install-recommends --no-install-suggests dialog apt-utils && \
    apt-get -y install --no-install-recommends --no-install-suggests yamllint && \
    apt-get -y install --no-install-recommends --no-install-suggests nodejs npm && \
    apt-get -y install --no-install-recommends --no-install-suggests cppcheck && \
    rm -rf /var/lib/apt/lists/* && \
    npm install -g --ignore-scripts markdownlint-cli

# Code source
COPY ./src ${WORKDIR}/src
COPY ./vcpkg.json ${WORKDIR}/vcpkg.json
COPY ./CMakeLists.txt ${WORKDIR}/CMakeLists.txt
COPY ./CMakePresets.json ${WORKDIR}/CMakePresets.json
COPY ./Makefile ${WORKDIR}/

# markdownlint conf
COPY ./.markdownlint.yaml ${WORKDIR}/

# yamllint conf
COPY ./.yamllint ${WORKDIR}/
COPY ./.yamlignore ${WORKDIR}/
COPY ./.gitignore ${WORKDIR}/

CMD ["make", "lint"]

FROM development AS testing

RUN apt-get -y update && \
    apt-get -y install --no-install-recommends --no-install-suggests gcovr && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder ${WORKDIR}/build ${WORKDIR}/

CMD ["make", "test"]

FROM ubuntu:24.04 AS production

ENV LOG_LEVEL=INFO
ENV BRUTEFORCE=false
ENV WORKDIR=/app
WORKDIR ${WORKDIR}

# COPY ./Makefile ${WORKDIR}/
COPY --from=builder ${WORKDIR}/build/src/lib/exercises/*.a ${WORKDIR}/

RUN useradd --user-group --system --create-home --no-log-init app
USER app

RUN ls -alhR

CMD ["make", "run"]
