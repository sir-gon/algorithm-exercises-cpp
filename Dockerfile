ARG BASE_IMAGE_VERSION=ubuntu:24.04
FROM ${BASE_IMAGE_VERSION} AS init

ENV WORKDIR=/app
WORKDIR ${WORKDIR}
ENV VCPKG_ROOT=/opt/vcpkg

RUN apt-get -y update && \
  apt-get -y install --no-install-recommends --no-install-suggests make && \
  rm -rf /var/lib/apt/lists/*

FROM init AS builder

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

# build tools
RUN apt-get update \
  && apt-get -y install --no-install-recommends --no-install-suggests build-essential cmake g++ make pkg-config \
  && rm -rf /var/lib/apt/lists/* \
  && make --version \
  && cmake --version \
  && g++ --version


ENV VCPKG_FORCE_SYSTEM_BINARIES=1
ENV VCPKG_VERSION=2025.07.25
ENV VCPKG_ROOT=/opt/vcpkg

# vcpkg Package Manager
RUN apt-get -y update && \
  apt-get -y install --no-install-recommends --no-install-suggests \
  ca-certificates curl git ninja-build unzip zip && \
  rm -rf /var/lib/apt/lists/* && \
  mkdir /opt/vcpkg && \
  git clone --branch ${VCPKG_VERSION} https://github.com/microsoft/vcpkg "${VCPKG_ROOT}" && \
  /opt/vcpkg/bootstrap-vcpkg.sh && \
  ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg && \
  rm -rf /var/lib/apt/lists/* && \
  vcpkg version

# sources
COPY ./src ${WORKDIR}/src
COPY ./vcpkg.json ${WORKDIR}/vcpkg.json
COPY ./CMakeLists.txt ${WORKDIR}/CMakeLists.txt
COPY ./CMakePresets.json ${WORKDIR}/CMakePresets.json
COPY ./Makefile ${WORKDIR}/

# dependencies
RUN make dependencies

LABEL vcpkg=enabled

# build
RUN ls -alhR && \
  mkdir build && \
  make build && \
  ls -alhR

CMD ["make", "build"]

FROM builder AS development

# CMD []

FROM builder AS lint

RUN apt-get update && \
  apt-get -y install --no-install-recommends --no-install-suggests gnupg software-properties-common && \
  rm -rf /var/lib/apt/lists/*
ADD https://apt.llvm.org/llvm-snapshot.gpg.key llvm-snapshot.gpg.key
RUN apt-key add llvm-snapshot.gpg.key && \
  apt-add-repository -y "deb https://apt.llvm.org/noble/ llvm-toolchain-noble-20 main" && \
  apt-get -y update && \
  apt-get -y install --no-install-recommends --no-install-suggests clang-format && \
  rm -rf /var/lib/apt/lists/*

ADD https://deb.nodesource.com/setup_22.x nodesource_setup.sh
RUN bash nodesource_setup.sh && \
  apt-get -y install --no-install-recommends --no-install-suggests nodejs && \
  npm install -g --ignore-scripts markdownlint-cli && \
  apt-get -y install --no-install-recommends --no-install-suggests python3-minimal python3-pip && \
  rm /usr/lib/python3.*/EXTERNALLY-MANAGED && \
  pip install --no-cache-dir yamllint && \
  apt-get -y install --no-install-recommends --no-install-suggests cppcheck && \
  rm -rf /var/lib/apt/lists/*

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
  apt-get -y install --no-install-recommends --no-install-suggests lcov && \
  rm -rf /var/lib/apt/lists/*

COPY --from=builder ${WORKDIR}/build ${WORKDIR}/

CMD ["make", "test"]

FROM ${BASE_IMAGE_VERSION} AS production

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
