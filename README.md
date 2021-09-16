# VSCP CLI Tools

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](http://choosealicense.com/licenses/mit/)
[![Repo Status](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Release](https://img.shields.io/github/release/BlueAndi/vscp-bootloader.svg)](https://github.com/BlueAndi/vscp-cli-tools/releases)

Command line interface tools used to maintain or simulate VSCP nodes.

- [VSCP CLI Tools](#vscp-cli-tools)
- [VSCP](#vscp)
- [Tools](#tools)
- [How To Build](#how-to-build)
  - [Prerequistes](#prerequistes)
    - [Linux](#linux)
    - [Windows](#windows)
  - [1 Clone The Repository](#1-clone-the-repository)
  - [2 Choose Project](#2-choose-project)
  - [3 Build](#3-build)
- [Issues, Ideas And Bugs](#issues-ideas-and-bugs)
- [License](#license)
- [Contribution](#contribution)

# VSCP

<img src="https://github.com/grodansparadis/vscp_logo/raw/master/vscp_logo.jpg" width="200px" alt="Logo" />

The Very Simple Control Protocol (VSCP), an open and free protocol for IoT/m2m automation tasks.

More information can be found on the main site http://www.vscp.org

# Tools

| Project    | Description |
| :------:   | :---------: |
| logger     | Tool which shows VSCP events on the command line, which are received by a daemon connection. |
| nodeSim | Simulates a single VSCP node. It can be called several times with different configurations to simulate more than one VSCP node. |
| programmer | Tool to program VSCP nodes over a VSCP daemon connection. It uses the VSCP standard bootloader algorithm. |

# How To Build

## Prerequistes

### Linux

Get the standard gcc build environment:
```
$ sudo apt update
$ sudo apt install build-essential
```

### Windows

1. Install MSYS2 (https://www.msys2.org/) and follow the complete installation instructions there. Only installing the MSYS2 binary is not enough! There are several steps in the MSYS2 shell necessary.
2. The gcc build environment will be available in the "MSYS MinGW 64-bit" shell.

## 1 Clone The Repository

The [vscp-framework](https://github.com/BlueAndi/vscp-framework) is added as git submodule. Therefore use
```
$ git clone --recursive https://github.com/BlueAndi/vscp-cli-tools.git
```

If already cloned and just a update of the vscp-framework shall be done, use:
```
$ git submodule update --remote
```

## 2 Choose Project

Choose the project by entering the corresponding folder, e.g. ```/nodeSim```.

## 3 Build

Build debug variant with ```make debug``` or use ```make release``` for the release variant.
The result will be in the ```/<project>/bin``` folder.

# Issues, Ideas And Bugs

If you have further ideas or you found some bugs, great! Create a [issue](https://github.com/BlueAndi/vscp-cli-tools/issues) or if you are able and willing to fix it by yourself, clone the repository and create a pull request.

# License
The whole source code is published under the [MIT license](http://choosealicense.com/licenses/mit/).

# Contribution
Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, shall be licensed as above, without any
additional terms or conditions.
