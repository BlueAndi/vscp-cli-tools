# VSCP CLI Tools

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](http://choosealicense.com/licenses/mit/)
[![Repo Status](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Release](https://img.shields.io/github/release/BlueAndi/vscp-bootloader.svg)](https://github.com/BlueAndi/vscp-cli-tools/releases)

Command line interface tools used to maintain or simulate VSCP nodes.

- [VSCP CLI Tools](#vscp-cli-tools)
- [VSCP](#vscp)
- [Tools](#tools)
- [How To Build](#how-to-build)
  - [Prerequisite](#prerequisite)
    - [Linux](#linux)
    - [Windows](#windows)
  - [1 Clone The Repository](#1-clone-the-repository)
  - [2 Choose Project](#2-choose-project)
  - [3 Build](#3-build)
- [Used Libraries](#used-libraries)
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

## Prerequisite

### Linux

1. Get the standard gcc build environment:
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```
2. Install expat packages:
    ```bash
    sudo apt install libexpat1
    sudo apt install libexpat1-dev
    ```
3. Install OpenSSL v1.1:
    1. Install dependencies:
    ```bash
    sudo apt install checkinstall zlib1g-dev
    ```
    2. Download OpenSSL:
    ```bash
    cd /usr/local/src/
    sudo wget https://www.openssl.org/source/openssl-1.1.1k.tar.gz
    sudo tar -xf openssl-1.1.1k.tar.gz
    cd openssl-1.1.1k.tar.gz
    ```
    3. Install and compile OpenSSL:
    ```bash
    sudo ./config --prefix=/usr/local/ssl --openssldir=/usr/local/ssl shared zlib
    sudo make
    sudo make test
    sudo make install
    ```
    4. Configure link libraries:
    ```bash
    cd /etc/ld.so.conf.d/
    sudo nano openssl-1.1.1k.conf
    ```
    Now add /usr/local/ssl/lib to the openssl-1.1.1k.conf file and save.
    5. Reload dynamic link:
    ```bash
    sudo ldconfig -v
    ```
4. Install vscp-helper-lib:
    1. Download vscp-helper-lib:
    ```bash
    sudo wget https://github.com/grodansparadis/vscp-helper-lib/releases/download/v15.0.0/libvscphelper_15.0.0_amd64.deb
    ```
    2. Install vscp-helper-lib:
    ```bash
    sudo apt install libvscphelper_15.0.0_amd64.deb
    ```

### Windows

1. Install MSYS2 (https://www.msys2.org/) and follow the complete installation instructions there. Only installing the MSYS2 binary is not enough! There are several steps in the MSYS2 shell necessary.
2. The gcc build environment will be available in the "MSYS2 MinGW UCRT 64-bit" shell.
3. Install expat packages:
    ```bash
    pacman -S libexpat
    pacman -S libexpat-devel
    ```
4. Install required visual studio runtime packages:
   * https://aka.ms/vs/17/release/vc_redist.x86.exe
   * https://aka.ms/vs/17/release/vc_redist.x64.exe

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

# Used Libraries

| Library | Description | License |
| - | - | - |
| [Expat](https://github.com/libexpat/libexpat) | Fast streaming XML parser. | MIT |
| [OpenSSL](https://github.com/openssl/openssl) | OpenSSL is a robust, commercial-grade, full-featured Open Source Toolkit for the TLS (formerly SSL), DTLS and QUIC (currently client side only) protocols. | Apache-2.0 |
| [vscp-helper-lib](https://github.com/grodansparadis/vscp-helper-lib) | VSCP helper functionality | MIT |

# Issues, Ideas And Bugs

If you have further ideas or you found some bugs, great! Create a [issue](https://github.com/BlueAndi/vscp-cli-tools/issues) or if you are able and willing to fix it by yourself, clone the repository and create a pull request.

# License
The whole source code is published under the [MIT license](http://choosealicense.com/licenses/mit/).

# Contribution
Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, shall be licensed as above, without any
additional terms or conditions.
