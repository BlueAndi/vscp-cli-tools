#!/bin/bash

# The VSCP helper library itself is part of this repository, see
# ./common/vscphelper. Only its runtime dependencies and the tool chain are
# installed here. The -dev packages pull in the matching runtime packages.

set -e

echo Update package lists
sudo apt-get update

echo Install build essentials
sudo apt-get install -y build-essential

echo Install expat
sudo apt-get install -y libexpat1-dev

echo Install OpenSSL
sudo apt-get install -y libssl-dev
