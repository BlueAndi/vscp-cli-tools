#!/bin/bash

echo Install expat
sudo apt install libexpat1
sudo apt install libexpat1-dev

echo Download and install vscp-helper-lib
sudo wget https://github.com/grodansparadis/vscp-helper-lib/releases/download/v15.0.0/libvscphelper_15.0.0_amd64.deb
sudo apt install ./libvscphelper_15.0.0_amd64.deb

echo Install dependencies
sudo apt install build-essential checkinstall zlib1g-dev

echo Download OpenSSL
cd /usr/local/src/
sudo wget https://www.openssl.org/source/openssl-1.1.1k.tar.gz
sudo tar -xf openssl-1.1.1k.tar.gz
cd openssl-1.1.1k.tar.gz

echo Install and compile OpenSSL
sudo ./config --prefix=/usr/local/ssl --openssldir=/usr/local/ssl shared zlib
sudo make
sudo make test
sudo make install

echo Configure link libraries
cd /etc/ld.so.conf.d/
echo "/usr/local/ssl/lib" >> openssl-1.1.1k.conf

echo Reload dynamic link
sudo ldconfig -v
