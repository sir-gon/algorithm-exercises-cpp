# Environment notes

OS: MacOS Sonoma 14.6.1 (23G93)

```sh
uname -a
```

```text
Darwin epoch.local 23.6.0 Darwin Kernel Version 23.6.0: Mon Jul 29 21:13:00 PDT 2024; root:xnu-10063.141.2~1/RELEASE_X86_64 x86_64
```

## Enable debugging with VSCode

<https://github.com/microsoft/vscode-cmake-tools/issues/3034>

## Tools

Required tools:

- Homebrew
- Xcode command line tools

<https://www.freecodecamp.org/news/install-xcode-command-line-tools/>

Then, the C++ local stack I choose:

```sh
brew install --cask cmake
brew install clang-format cppcheck make vcpkg

```

## Visual Studio Code extensions

Suggested for a C++ stack

```sh
code --install-extension ms-vscode.cpptools-extension-pack
code --install-extension ms-vscode.cmake-tools
code --install-extension xaver.clang-format
code --install-extension ryanluker.vscode-coverage-gutters
code --install-extension NathanJ.cpp-tools-plugin
code --install-extension ms-vscode.makefile-tools
```

General purpose

```sh
code --install-extension ms-azuretools.vscode-docker
code --install-extension EditorConfig.EditorConfig
code --install-extension donjayamanne.githistory
code --install-extension shd101wyy.markdown-preview-enhanced
code --install-extension DavidAnson.vscode-markdownlint
code --install-extension bpruitt-goddard.mermaid-markdown-syntax-highlighting
code --install-extension esbenp.prettier-vscode
code --install-extension redhat.vscode-yaml
```

Optional (cosmetic purpose)

```sh
code --install-extension aaron-bond.better-comments
code --install-extension isotechnics.commentlinks
code --install-extension johnpapa.vscode-peacock
code --install-extension vscode-icons-team.vscode-icons
```

Extra for complementary external services

```sh
code --install-extension snyk-security.snyk-vulnerability-scanner
code --install-extension SonarSource.sonarlint-vscode
code --install-extension github.vscode-github-actions

```
