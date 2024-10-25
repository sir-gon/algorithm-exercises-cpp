## REFERENCES:
## (1) Passing environment variable with fallback value to Makefile:
##    https://stackoverflow.com/a/70772707/6366150
## (2) Export environment variables inside "make environment"
##		https://stackoverflow.com/a/49524393/6366150
## (3) Uppercase to lowercase and vice versa
##		https://community.unix.com/t/uppercase-to-lowercase-and-vice-versa/285278/6
## (4) How do I trim leading and trailing whitespace from each line of some output?
## 		https://unix.stackexchange.com/a/279222/233927
############################################################################

## (1) ## Allowed values: info | warn | error | debug
LOG_LEVEL ?= info
## (3) (4)
LOG_LEVEL :=$(shell echo '${LOG_LEVEL}'| tr '[:lower:]' '[:upper:]'| tr -d '[:blank:]')

## (1) ## Allowed values: true | false
BRUTEFORCE ?= false
## (3) (4)
BRUTEFORCE :=$(shell echo '${BRUTEFORCE}'| tr '[:lower:]' '[:upper:]'| tr -d '[:blank:]')

# DOCKER
BUILDKIT_PROGRESS=plain
DOCKER_COMPOSE=docker compose

# TOOLS
COVERAGE_TOOL_OPTS=--config-file .lcovrc --ignore-errors empty --ignore-errors inconsistent

# C++ specific
SRC_DIR = src
FILES := $(shell find $(SRC_DIR) -name '*.cpp' -o -name '*.h' -o -name '*.hpp' -o -name '*.inl')

.MAIN: test
.PHONY: all clean dependencies help list test outdated
.EXPORT_ALL_VARIABLES: # (2)

help: list

list:
	@LC_ALL=C $(MAKE) -pRrq -f $(lastword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/^# File/,/^# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'

env:
	@echo "################################################################################"
	@echo "## Environment: ################################################################"
	@echo "################################################################################"
	@printenv | grep -E "LOG_LEVEL|BRUTEFORCE|BUILDKIT_PROGRESS"
	@echo "################################################################################"

clean:
	sh -c "rm -fr -v *.gcov" || true
	sh -c "rm -fr -v ./build/*" || true
	sh -c "rm -fr -v ./build/.*" || true
	touch ./build/.gitkeep
	sh -c "rm -fr -v ./coverage/*" || true
	touch ./coverage/.gitkeep
	sh -c "rm -fr -v ./vcpkg_installed" || true

prebuild: dependencies
	cmake --preset debug -B build

build: prebuild
	cmake --build build --verbose

dependencies:
	vcpkg --x-wait-for-lock integrate install
	vcpkg --x-wait-for-lock install

lint/markdown:
	markdownlint '**/*.md' && echo '✔  Your code looks good.'

lint/yaml:
	yamllint --stric . && echo '✔  Your code looks good.'

lint: lint/markdown lint/yaml test/styling test/static

test/static: prebuild
	cppcheck \
		--project=build/compile_commands.json \
		--enable=all \
		--check-level=exhaustive \
		--std=c++17 \
		--library=posix \
		--inconclusive \
		--inline-suppr \
		--error-exitcode=13 \
		--suppress=missingIncludeSystem \
		--showtime=summary

test/styling:
	clang-format --dry-run --Werror $(FILES)

format:
	clang-format -i --verbose $(FILES)

test: env dependencies build
	cd build && make test

coverage: test
	lcov ${COVERAGE_TOOL_OPTS} -o coverage/lcov.info --no-external --capture --exclude "build/vcpkg_installed" --exclude "test.cpp" --directory .

coverage/html: coverage
	genhtml ${COVERAGE_TOOL_OPTS} -o coverage/ --show-details --legend coverage/lcov.info
	open coverage/index.html

outdated:

update: dependencies outdated

upgrade: update

compose/build: env
	${DOCKER_COMPOSE} --profile lint build
	${DOCKER_COMPOSE} --profile testing build
	${DOCKER_COMPOSE} --profile production build

compose/rebuild: env
	${DOCKER_COMPOSE} --profile lint build --no-cache
	${DOCKER_COMPOSE} --profile testing build --no-cache
	${DOCKER_COMPOSE} --profile production build --no-cache

compose/lint/markdown: compose/build
	${DOCKER_COMPOSE} --profile lint build
	${DOCKER_COMPOSE} --profile lint run --rm algorithm-exercises-cpp-lint make lint/markdown

compose/lint/yaml: compose/build
	${DOCKER_COMPOSE} --profile lint run --rm algorithm-exercises-cpp-lint make lint/yaml

compose/test/styling: compose/build
	${DOCKER_COMPOSE} --profile lint run --rm algorithm-exercises-cpp-lint make test/styling

compose/test/static: compose/build
	${DOCKER_COMPOSE} --profile lint run --rm algorithm-exercises-cpp-lint make test/static

compose/lint: compose/lint/markdown compose/lint/yaml compose/test/styling compose/test/static

compose/test: compose/build
	${DOCKER_COMPOSE} --profile testing run --rm algorithm-exercises-cpp-test make test

compose/run: compose/build
	${DOCKER_COMPOSE} --profile production run --rm algorithm-exercises-cpp ls -alhR

all: env dependencies test

run:
	ls -alh
