FROM alpine:3.24 AS init

ENV WORKDIR=/app
WORKDIR ${WORKDIR}

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC


RUN apk add --update --no-cache \
  ## common permanent packages
  "make=4.4.1-r4"

COPY ./Makefile ${WORKDIR}/

SHELL ["/bin/ash", "-o", "pipefail", "-c"]
RUN apk --update add --no-cache \
    "ca-certificates=20260909-r0" \
    "tzdata=2026d-r0" \
    "gcompat=1.1.0-r4" \
  && update-ca-certificates \
  && apk --update add --no-cache \
    ## add ephemeral packages
    "curl=8.22.0-r0" \
    "tar=1.35-r5" \
    # CMAKE from Kitware repository
    && curl -fsSLH "Cache-Control: no-cache" --proto "=https" https://github.com/Kitware/CMake/releases/download/v4.4.0/cmake-4.4.0-linux-x86_64.tar.gz \
    | tar -xz --strip-components=1 -C /usr/local \
  ## remove ephemeral packages
  && apk del curl gpg tar

FROM init AS builder

ARG GENERATE_ASM=0
ENV GENERATE_ASM=${GENERATE_ASM}

# build tools
RUN apk --update add --no-cache \
  "build-base=0.5-r4" \
  "pkgconf=2.5.1-r0" \
  ## test tools
  && gcc --version \
  && g++ --version \
  && make --version \
  && cmake --version

# # vcpkg Package Manager
ENV VCPKG_FORCE_SYSTEM_BINARIES=1
ENV VCPKG_VERSION=2026.07.29
ENV VCPKG_ROOT=/opt/vcpkg

# vcpkg Package Manager
RUN apk --update add --no-cache \
    "curl=8.22.0-r0" \
    "git=2.54.0-r0" \
    "patchelf=0.18.0-r3" \
    "samurai=1.2-r8" \
    "unzip=6.0-r16" \
    "zip=3.0-r13" \
  && mkdir /opt/vcpkg \
  && git clone --branch "${VCPKG_VERSION}" https://github.com/microsoft/vcpkg "${VCPKG_ROOT}" \
  && /opt/vcpkg/bootstrap-vcpkg.sh \
  && ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg \
  && rm -rf /var/lib/apt/lists/* \
  && vcpkg version

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

CMD []

FROM init AS lint

# # Instala sólo lo mínimo necesario para linting (cmake, clang-format, cppcheck)
RUN apk --update add --no-cache \
  "clang-extra-tools=22.1.3-r2" \
  "cppcheck=2.21.0-r0"

LABEL lint-phase=enabled
LABEL clang-format=enabled
LABEL cppcheck=enabled

# Tooling test
RUN clang-format --version && \
  cppcheck --version && \
  make --version

# Copia sólo lo necesario para ejecutar las comprobaciones
COPY ./src ${WORKDIR}/src
COPY ./Makefile ${WORKDIR}/
RUN mkdir -p "${WORKDIR}"/build
COPY --from=builder ${WORKDIR}/build/compile_commands.json ${WORKDIR}/build/compile_commands.json

CMD ["make", "lint-no-deps"]

FROM init AS testing

RUN apk --update add --no-cache \
  # libasan required (AdressSanitizer)
  "gcc=15.2.0-r5" \
  # coverage
  "lcov=2.3.1-r1" \
  # runtime required libraries
  "libgcc=15.2.0-r5" \
  "libstdc++=15.2.0-r5"

# COPY --from=builder ${WORKDIR}/build ${WORKDIR}/build
COPY --from=builder ${WORKDIR} ${WORKDIR}

CMD ["make", "test-no-deps"]

FROM alpine:3.24 AS production

ENV LOG_LEVEL=INFO
ENV BRUTEFORCE=false
ENV WORKDIR=/app
WORKDIR ${WORKDIR}

COPY --from=builder ${WORKDIR}/build/src/lib/exercises/*.a ${WORKDIR}/

RUN addgroup -S -g 1001 app \
    && adduser -S -u 1001 -G app -h /home/app app
USER 1001

RUN ls -alhR

CMD ["make", "run"]
