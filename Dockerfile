FROM ubuntu:26.04 AS init

ENV WORKDIR=/app
WORKDIR ${WORKDIR}
ENV VCPKG_ROOT=/opt/vcpkg

RUN apt-get -y update && \
  apt-get -y install --no-install-recommends --no-install-suggests ca-certificates make && \
  rm -rf /var/lib/apt/lists/*

FROM init AS builder
ARG GENERATE_ASM=0
ENV GENERATE_ASM=${GENERATE_ASM}

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

# build tools
RUN apt-get update \
  && apt-get -y install --no-install-recommends --no-install-suggests \
    curl gpg lsb-release \
  && apt-get -y install --no-install-recommends --no-install-suggests \
    build-essential g++ gcc gpg \
    lsb-release make pkg-config \
  # CMAKE from Kitware repository
  && curl --proto "=https" -fsSL https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null \
  | gpg --dearmor -o /usr/share/keyrings/kitware-archive-keyring.gpg \
  && echo "deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu $(lsb_release -cs) main" \
  > /etc/apt/sources.list.d/kitware.list \
  && apt-get -y autoremove curl lsb-release gpg \
  && apt-get update \
  && apt-get install -y --no-install-recommends cmake \
  ## clean up
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/* \
  && make --version \
  && gcc --version \
  && g++ --version \
  && cmake --version

# vcpkg Package Manager
ENV VCPKG_FORCE_SYSTEM_BINARIES=1
ENV VCPKG_VERSION=2026.07.29
ENV VCPKG_ROOT=/opt/vcpkg

# vcpkg Package Manager
RUN apt-get -y update && \
  apt-get -y install --no-install-recommends --no-install-suggests \
    curl \
  && apt-get -y install --no-install-recommends --no-install-suggests \
    git ninja-build unzip zip \
  && rm -rf /var/lib/apt/lists/* \
  && mkdir /opt/vcpkg \
  && git clone --branch "${VCPKG_VERSION}" https://github.com/microsoft/vcpkg "${VCPKG_ROOT}" \
  && /opt/vcpkg/bootstrap-vcpkg.sh \
  && apt-get -y autoremove curl \
  && ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg && \
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

FROM init AS lint

# Instala sólo lo mínimo necesario para linting (cmake, clang-format, cppcheck)
RUN apt-get update && \
  apt-get -y install --no-install-recommends --no-install-suggests \
    clang-format cmake cppcheck \
  && rm -rf /var/lib/apt/lists/*

# Tooling test
RUN clang-format --version && \
  cppcheck --version && \
  cmake --version

# Copia sólo lo necesario para ejecutar las comprobaciones
COPY ./src ${WORKDIR}/src
COPY ./Makefile ${WORKDIR}/
RUN mkdir -p "${WORKDIR}"/build
COPY --from=builder ${WORKDIR}/build/compile_commands.json ${WORKDIR}/build/compile_commands.json

CMD ["make", "lint-no-deps"]

FROM development AS testing

RUN apt-get -y update && \
  apt-get -y install --no-install-recommends --no-install-suggests lcov && \
  rm -rf /var/lib/apt/lists/*

COPY --from=builder ${WORKDIR}/build ${WORKDIR}/

CMD ["make", "test"]

FROM ubuntu:26.04 AS production

ENV LOG_LEVEL=INFO
ENV BRUTEFORCE=false
ENV WORKDIR=/app
WORKDIR ${WORKDIR}

COPY --from=builder ${WORKDIR}/build/src/lib/exercises/*.a ${WORKDIR}/

RUN useradd --user-group --system --create-home --no-log-init app
USER app

RUN ls -alhR

CMD ["make", "run"]
