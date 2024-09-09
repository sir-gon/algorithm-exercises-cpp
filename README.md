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

## What is this?

This repository is part of a series that share and solve the same [objectives](#objetives),
with the difference that each one is based on a different software ecosystem,
depending on the chosen programming language:

- [Modern Javascript: algorithm-exercises-js](https://github.com/sir-gon/algorithm-exercises-js)
- [Python 3.x: algorithm-exercises-py](https://github.com/sir-gon/algorithm-exercises-py)
- [Typescript: algorithm-exercises-cpp](https://github.com/sir-gon/algorithm-exercises-cpp)
- [Go / Golang: algorithm-exercises-go](https://github.com/sir-gon/algorithm-exercises-go)
- [Java: algorithm-exercises-java](https://github.com/sir-gon/algorithm-exercises-java)
- [.NET / C#: algorithm-exercises-cpp](https://github.com/sir-gon/algorithm-exercises-cpp)

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

## Install and Run

### Install and Run directly

Using a NodeJS runtime in your SO. You must install dependencies:

```bash
cd build
cmake ..
make
make test
```

## About development

```sh
cmake --version
```

```text
cmake version 3.30.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

```sh
g++ --version
```

```text
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: x86_64-apple-darwin23.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

```sh
brew info catch2
```

```text
==> catch2: stable 3.7.0 (bottled)
Modern, C++-native, header-only, test framework
https://github.com/catchorg/Catch2
Installed
/usr/local/Cellar/catch2/3.7.0 (230 files, 2.7MB) *
  Poured from bottle using the formulae.brew.sh API on 2024-09-08 at 19:35:03
From: https://github.com/Homebrew/homebrew-core/blob/HEAD/Formula/c/catch2.rb
License: BSL-1.0
==> Dependencies
Build: cmake ✘
==> Analytics
install: 602 (30 days), 1,327 (90 days), 5,032 (365 days)
install-on-request: 561 (30 days), 1,232 (90 days), 4,619 (365 days)
build-error: 0 (30 days)
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
It appears that you have answered your own question. There is nothing quite like that "Aha!" moment when you finally beat a problem which you have been working on for some time. It is often through the best of intentions in wishing to share our insights so that others can enjoy that moment too. Sadly, that will rarely be the case for your readers. Real learning is an active process and seeing how it is done is a long way from experiencing that epiphany of discovery. Please do not deny others what you have so richly valued yourself.

However, the rule about sharing solutions outside of Project Euler does not apply to the first one-hundred problems, as long as any discussion clearly aims to instruct methods, not just provide answers, and does not directly threaten to undermine the enjoyment of solving later problems. Problems 1 to 100 provide a wealth of helpful introductory teaching material and if you are able to respect our requirements, then we give permission for those problems and their solutions to be discussed elsewhere.
```

If you have better answers or optimal solutions, fork and PR-me

Enjoy 😁 !

## Status

### License

[LICENSE.md](LICENSE.md)

### Coverage

[![Coverage](https://codecov.io/gh/sir-gon/algorithm-exercises-cpp/graphs/tree.svg?token=YZ41BE67E4)](https://codecov.io/gh/sir-gon/algorithm-exercises-cpp)
