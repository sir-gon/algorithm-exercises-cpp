# Algorithm Exercises (C++17)

[![C++17 CI](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/cpp.yml/badge.svg)](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/cpp.yml)
[![CppCheck Lint](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/cppcheck.yml)
[![Markdown Lint](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/markdown-lint.yml/badge.svg)](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/markdown-lint.yml)
[![YAML lint](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/yamllint.yml/badge.svg)](https://github.com/sir-gon/algorithm-exercises-cpp/actions/workflows/yamllint.yml)

![GitHub](https://img.shields.io/github/license/sir-gon/algorithm-exercises-cpp)
![GitHub language count](https://img.shields.io/github/languages/count/sir-gon/algorithm-exercises-cpp)
![GitHub top language](https://img.shields.io/github/languages/top/sir-gon/algorithm-exercises-cpp)
[![CodeFactor](https://www.codefactor.io/repository/github/sir-gon/algorithm-exercises-cpp/badge)](https://www.codefactor.io/repository/github/sir-gon/algorithm-exercises-cpp)
[![codecov](https://codecov.io/gh/sir-gon/algorithm-exercises-cpp/branch/main/graph/badge.svg?token=YZ41BE67E4)](https://codecov.io/gh/sir-gon/algorithm-exercises-cpp)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=sir-gon_algorithm-exercises-cpp&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=sir-gon_algorithm-exercises-cpp)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=sir-gon_algorithm-exercises-cpp&metric=coverage)](https://sonarcloud.io/summary/new_code?id=sir-gon_algorithm-exercises-cpp)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=sir-gon_algorithm-exercises-cpp&metric=bugs)](https://sonarcloud.io/summary/new_code?id=sir-gon_algorithm-exercises-cpp)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=sir-gon_algorithm-exercises-cpp&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=sir-gon_algorithm-exercises-cpp)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=sir-gon_algorithm-exercises-cpp&metric=duplicated_lines_density)](https://sonarcloud.io/summary/new_code?id=sir-gon_algorithm-exercises-cpp)

## TL;DR

Algorithms Exercises solved in [C++17](https://en.cppreference.com/w/cpp/17),
running with [Catch2](https://github.com/catchorg/Catch2) testing suite throug [CMake](https://cmake.org/).
Developed with TDD.

- Package Manager for libraries / dependencies [**vcpkg**](https://vcpkg.io/)
- JSON reading with [@nlohmann/json](https://github.com/nlohmann/json)

[![C++17](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/cpp/17)
[![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/)
[![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white)](https://www.docker.com/)

Go to [Install and run](#install-and-run)

## What is this?

This repository is part of a series that share and solve the same [objectives](#objetives),
with the difference that each one is based on a different software ecosystem,
depending on the chosen programming language:

- [Modern Javascript: algorithm-exercises-js](https://github.com/sir-gon/algorithm-exercises-js)
- [Typescript: algorithm-exercises-ts](https://github.com/sir-gon/algorithm-exercises-ts)

- [Python 3.x: algorithm-exercises-py](https://github.com/sir-gon/algorithm-exercises-py)
- [Go / Golang: algorithm-exercises-go](https://github.com/sir-gon/algorithm-exercises-go)

- [Java: algorithm-exercises-java](https://github.com/sir-gon/algorithm-exercises-java)
- [.NET / C#: algorithm-exercises-csharp](https://github.com/sir-gon/algorithm-exercises-csharp)
- [C++17: algorithm-exercises-cpp](https://github.com/sir-gon/algorithm-exercises-csharp-cpp)

## Objetives

### Functional

- For academic purposes, it is an backup of some algorithm exercises
(with their solutions), proposed by various sources:
[leetcode, hackerrank, projecteuler](#algorithm-excersices-sources), ...

- The solutions must be written on "vanilla code", that is,
avoiding as much as possible the use of external libraries (in runtime).

- Adoption of methodology and good practices.
Each exercise is implemented as a unit test set,
using TDD (Test-driven Development) and Clean Code ideas.

### Technical

Foundation of a project that supports:

- Explicit **typing** when the language supports it, even when it is not mandatory.
- Static Code Analysis (**Lint**) of code, scripts and documentation.
- Uniform **Code Styling**.
- **Unit Test** framework.
- **Coverge** collection. High coverage percentage. Equal or close to 100%.
- **Pipeline** (Github Actions). Each command must take care of its
return status code.
- **Docker**-based workflow to replicate behavior in any environment.
- Other tools to support the reinforcement of software development **good practices**.

## Install and Run

- (⭐️) [Install and run directly with make](#install-and-run-directly-with-make)
require runtime tools and GNU make installed in your SO.
- [Install and in Docker](#install-and-running-with-docker-) require Docker and
docker compose installed.
- [Install and in Docker with make](#install-and-running-with-docker--using-make)
require Docker, docker compose and GNU make installed.

⭐️: Prefered way.

### Install and run directly with make

It is assumed that the following tools have already been installed:

- [**GNU make**](https://www.gnu.org/software/make/)
- [**CMake**](https://cmake.org/)
- [**vcpkg**](https://vcpkg.io/)
- [**CppCheck**](https://cppcheck.sourceforge.io/)
- [**(LLVM) clang-format**](https://clang.llvm.org/docs/ClangFormat.html)

Using a  runtime in your SO. You must install dependencies:

```bash
make dependencies
make lint # optional
make build
make test
```

#### Test run with alternative behaviors

Not implemented yet

#### Examples running tests with alternative behaviors

### Install and Running with Docker 🐳

Build an image of the test stage.
Then creates and ephemeral container an run tests.

```bash
docker compose build algorithm-exercises-cpp
docker compose build algorithm-exercises-cpp-lint
docker compose build algorithm-exercises-cpp-test
docker compose build algorithm-exercises-cpp-dev
```

```bash
docker compose --profile testing run --rm algorithm-exercises-cpp-test
```

### Install and Running with Docker 🐳 using make

```bash
make compose/build
make compose/lint # optional
make compose/test
```

## About development

```sh
cmake --version
```

```text
cmake version 3.30.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

---

```sh
vcpkg --version
```

```text
vcpkg package management program version 2024-08-01-2024.08.01

See LICENSE.txt for license information.
```

---

```sh
g++ --version
```

```text
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: x86_64-apple-darwin23.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

---

```sh
cppcheck --version
```

```text
Cppcheck 2.15.0
```

## Algorithm excersices sources

- [Leetcode](https://leetcode.com/) online platform for
coding interview preparation.
- [HackerRank](https://www.hackerrank.com/) competitive programming challenges
for both consumers and businesses.
- [Project Euler](https://projecteuler.net/) a series of computational problems
intended to be solved with computer programs.

Use these answers to learn some tip and tricks for algorithms tests.

### Disclaimer. Why I publish solutions?

As Project Euler says:

<https://projecteuler.net/about#publish>

```text
I learned so much solving problem XXX, so is it okay to publish my solution elsewhere?
It appears that you have answered your own question. There is  thing quite like that "Aha!" moment when you finally beat a problem which you have been working on for some time. It is often through the best of intentions in wishing to share our insights so that others can enjoy that moment too. Sadly, that will rarely be the case for your readers. Real learning is an active process and seeing how it is done is a long way from experiencing that epiphany of discovery. Please do not deny others what you have so richly valued yourself.

However, the rule about sharing solutions outside of Project Euler does not apply to the first one-hundred problems, as long as any discussion clearly aims to instruct methods, not just provide answers, and does not directly threaten to undermine the enjoyment of solving later problems. Problems 1 to 100 provide a wealth of helpful introductory teaching material and if you are able to respect our requirements, then we give permission for those problems and their solutions to be discussed elsewhere.
```

If you have better answers or optimal solutions, fork and PR-me

Enjoy 😁 !

## Status

### License

[LICENSE.md](LICENSE.md)

### Coverage

[![Coverage](https://codecov.io/gh/sir-gon/algorithm-exercises-cpp/graphs/tree.svg?token=YZ41BE67E4)](https://codecov.io/gh/sir-gon/algorithm-exercises-cpp)
