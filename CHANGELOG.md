# Changelog

## 3.1.0

* vscp-helper-lib updated from v15.0.0 to v15.2.242.
  * The library is no longer installed system wide on linux. It is used from ```/common/vscphelper``` on both platforms and copied next to the binary during the build.
  * ```setup_linux.sh``` installs only the tool chain and the runtime dependencies now. Building OpenSSL from source is not necessary anymore, because OpenSSL 3 is used, which is part of the supported distributions.
  * The windows release contains no import library, therefore the tools link directly against ```libvscphelper15.dll```.
  * The windows release contains none of the DLLs which the helper library depends on. ```libcrypto-3-x64.dll``` and ```libssl-3-x64.dll``` (OpenSSL 3) were added, ```libexpat.dll``` and ```pthreadVCE3.dll``` are kept from v15.0.0.
  * The helper library is only released for windows in release mode. The debug/release separation of the library folder was removed, because it had no effect on linux either.
  * ```vscp.h``` doesn't include ```canal.h```, ```vscp-class.h``` and ```vscp-type.h``` anymore. The new ```/common/vscphelper_compat.h``` wraps the helper library headers, so that the vendored headers can be kept unmodified.

## 3.0.0

* Build environment updated for using MSYS2 MinGW UCRT 64-bit.
* Using VSCP-framework v2.1.0
* Using VSCP-bootloader v3.0.0

## 2.0.0

* [VSCP-framework repository](https://github.com/BlueAndi/vscp-framework) was restructured and the CLI tools moved to this dedicated repository.
* vscp-helper-lib updated to v15.0.0. The linux variant is only in release mode available. The windows variant in release and debug mode.
* ```dataNum``` variable in the VSCP message (from VSCP-framework) was renamed to ```dataSize```. Therefore the source code was updated accordingly.
