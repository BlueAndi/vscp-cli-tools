# VSCP CLI Tools <!-- omit in toc -->

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](http://choosealicense.com/licenses/mit/)
[![Repo Status](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Release](https://img.shields.io/github/release/BlueAndi/vscp-bootloader.svg)](https://github.com/BlueAndi/vscp-cli-tools/releases)

Command line interface tools used to maintain or simulate VSCP nodes.

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
  - [Updating The VSCP Helper Library](#updating-the-vscp-helper-library)
- [Issues, Ideas And Bugs](#issues-ideas-and-bugs)
- [License](#license)
- [Contribution](#contribution)

## VSCP

<img src="https://github.com/grodansparadis/vscp_logo/raw/master/vscp_logo.jpg" width="200px" alt="Logo" />

The Very Simple Control Protocol (VSCP), an open and free protocol for IoT/m2m automation tasks.

More information can be found on the main site [http://www.vscp.org](http://www.vscp.org)

## Tools

|  Project   |                                                           Description                                                           |
| :--------: | :-----------------------------------------------------------------------------------------------------------------------------: |
|   logger   |                  Tool which shows VSCP events on the command line, which are received by a daemon connection.                   |
|  nodeSim   | Simulates a single VSCP node. It can be called several times with different configurations to simulate more than one VSCP node. |
| programmer |            Tool to program VSCP nodes over a VSCP daemon connection. It uses the VSCP standard bootloader algorithm.            |

## How To Build

### Prerequisite

#### Linux

1. Open a terminal.
2. Call ```setup_linux.sh```

#### Windows

1. Install MSYS2 ([https://www.msys2.org/](https://www.msys2.org/)) and follow the complete installation instructions there. Only installing the MSYS2 binary is not enough! There are several steps in the MSYS2 shell necessary.
2. The gcc build environment will be available in the "MSYS2 MinGW UCRT 64-bit" shell. Use this shell for all following steps and for building.
3. Install the tool chain and the expat package:

    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc
    pacman -S mingw-w64-ucrt-x86_64-make
    pacman -S mingw-w64-ucrt-x86_64-expat
    ```

4. Install the required visual studio runtime package, which the VSCP helper library depends on:
    - [https://aka.ms/vs/17/release/vc_redist.x64.exe](https://aka.ms/vs/17/release/vc_redist.x64.exe)

### 1 Clone The Repository

The [vscp-framework](https://github.com/BlueAndi/vscp-framework) is added as git submodule. Therefore use:

```bash
git clone --recursive https://github.com/BlueAndi/vscp-cli-tools.git
```

If already cloned and just a update of the vscp-framework shall be done, use:

```bash
git submodule update --remote
```

### 2 Choose Project

Choose the project by entering the corresponding folder, e.g. ```/nodeSim```.

### 3 Build

Build debug variant with ```make debug``` or use ```make release``` for the release variant.
The result will be in the ```/<project>/bin``` folder.

On windows the MSYS2 MinGW UCRT 64-bit environment provides ```mingw32-make```, therefore use ```mingw32-make debug``` resp. ```mingw32-make release``` there.

## Used Libraries

| Library                                                              | Description                                                                                                                                                | License    |
| -------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| [Expat](https://github.com/libexpat/libexpat)                        | Fast streaming XML parser.                                                                                                                                 | MIT        |
| [OpenSSL](https://github.com/openssl/openssl)                        | OpenSSL is a robust, commercial-grade, full-featured Open Source Toolkit for the TLS (formerly SSL), DTLS and QUIC (currently client side only) protocols. | Apache-2.0 |
| [vscp-helper-lib](https://github.com/grodansparadis/vscp-helper-lib) | VSCP helper functionality (v15.2.242)                                                                                                                      | MIT        |

The VSCP helper library is not installed system wide, but part of this repository in ```/common/vscphelper```. Its headers are taken over from the upstream release without modification, see ```/common/vscphelper_compat.h``` for the workarounds which are necessary on top. The shared libraries are copied next to the binary during the build, therefore no further installation is required.

### Updating The VSCP Helper Library

The prebuilt binaries are taken from the [vscp-helper-lib releases](https://github.com/grodansparadis/vscp-helper-lib/releases). For v15.2.242 these are:

| File in ```/common/vscphelper```    | Origin                                                                      |
| ----------------------------------- | --------------------------------------------------------------------------- |
| ```*.h```                           | ```libvscphelper_windows_x64_15.2.242.zip```, ```include/```                |
| ```lib/win64/libvscphelper15.dll``` | ```libvscphelper_windows_x64_15.2.242.zip```, ```lib/```                    |
| ```lib/linux/libvscphelper15.so```  | ```libvscphelper_linux_x64_15.2.242.deb```, ```usr/lib/x86_64-linux-gnu/``` |

The headers in the Debian package and in the Windows archive are identical.

Note that the Windows release archive contains neither an import library nor all DLLs which ```libvscphelper15.dll``` depends on. Therefore:

- The tools link directly against the DLL, see ```-l:libvscphelper15.dll``` in the makefiles.
- ```libcrypto-3-x64.dll``` and ```libssl-3-x64.dll``` are taken from the MSYS2 MinGW UCRT 64-bit environment (```/ucrt64/bin```), provided by the ```mingw-w64-ucrt-x86_64-openssl``` package.
- ```libexpat.dll``` and ```pthreadVCE3.dll``` are still the ones which were delivered with v15.0.0.

The Microsoft Visual C++ runtime DLLs are not part of the repository, because they are installed by the visual studio runtime package, see the Windows prerequisites.

## Issues, Ideas And Bugs

If you have further ideas or you found some bugs, great! Create a [issue](https://github.com/BlueAndi/vscp-cli-tools/issues) or if you are able and willing to fix it by yourself, clone the repository and create a pull request.

## License

The whole source code is published under the [MIT license](http://choosealicense.com/licenses/mit/).

## Contribution

Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, shall be licensed as above, without any
additional terms or conditions.
