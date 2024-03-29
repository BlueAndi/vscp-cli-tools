# The MIT License (MIT)
# 
# Copyright (c) 2014 - 2024 Andreas Merkle
# http://www.blue-andi.de
# vscp@blue-andi.de
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

################################################################################
# Makefile for VSCP PC logger
# Author: Andreas Merkle, http://www.blue-andi.de
#
################################################################################

################################################################################
# Configuration
################################################################################

# Software version
VERSION= 0.1.0

# Binary file name
BIN= vscpProgrammerPc

# General include directories
INCLUDES= -I. \
		-I../common \
		-I ../common/vscp-bootloader/src \
		-I../common/vscphelper

# Sources
SOURCES= main.c \
		intelHexParser.c \
		../common/vscp-bootloader/src/crc16ccitt.c \
		../common/cmdLineParser.c \
		../common/log.c \
		../common/platform.c

# Include all source pathes here like ../src1:../src2
VPATH= ../common:../common/vscp-bootloader/src

# Determine build type
ifeq ($(MAKECMDGOALS),debug)
BUILDTYPE= debug
endif

ifeq ($(MAKECMDGOALS),release)
BUILDTYPE= release
endif

# Determine operating system
ifeq ($(OS),Windows_NT)
BUILDOS= win64
else
BUILDOS= linux
endif

# Library search path (-L...)
LIBPATH= -L../common/vscphelper/lib/$(BUILDOS)/$(BUILDTYPE)

# Libraries (-l...)
LIBRARIES= -lm -lvscphelper

# Windows specific part
ifeq ($(OS),Windows_NT)
LIBRARIES+= -lws2_32
else
LIBRARIES+= -ldl -lexpat
endif

# Preprocessor defines
PREPROC= -D_REENTRANT -DVERSION=\"$(VERSION)\" -DBUILDTYPE=\"$(BUILDTYPE)\"

# General compiler flags independent of debug or release build
# -Wall                : Enable all warnings
# -ffunction-sections -fdata-sections : Remove unused functions
# -fshort-enums        : Allocate to an enum type only as many bytes as it needs for the declared range of possible values.
# -std=gnu99           : Define the C standard
# -funsigned-bitfields : Bitfields always unsigned
CFLAGS= -Wall -ffunction-sections -fdata-sections -fshort-enums -std=gnu99 -funsigned-bitfields

# General linker flags independent of debug or release build
# -Wall             : Enable all warnings
# -Wl,-Map,foo.map  : Create map file
# -Wl,--cref        : Add cross reference to map file
# -Wl,--gc-sections : Enable garbage collection of unused input sections
# -Wl,-rpath='$$ORIGIN/../lib/linux' : Set shared object search path
LDFLAGS= -Wall -Wl,-Map,$(BINDIR)/$(BIN).map -Wl,--cref -Wl,--gc-sections -Wl,-rpath='$$ORIGIN/../../../../common/pc/vscphelper/lib/linux/$(BUILDTYPE)'

ifeq ($(MAKECMDGOALS),debug)

# Additional C compiler flags for debug build
# -g1             : Minimal debug information
# -g              : Default debug information
# -g3             : Maximum debug information
# -O1             : Optimization level
# -ftest-coverage : Generate additional coverage information
# -fprofile-arcs  : Generate profile output
CFLAGS+= -g -O1

# Additional linker flags for debug build
# -ftest-coverage : Enable coverage
# -fprofile-arcs  : Enable profiling
LDFLAGS+=

# The flag indicates in the name of the DLL whether its a release or debug version
DLLFLAG= d

endif

ifeq ($(MAKECMDGOALS),release)

# Additional C compiler flags for release build
# -Os             : Optimization level
# -ftest-coverage : Generate additional coverage information
# -fprofile-arcs  : Generate profile output
CFLAGS+= -Os

# Additional linker flags for release build
# -ftest-coverage : Enable coverage
# -fprofile-arcs  : Enable profiling
LDFLAGS+=

# The flag indicates in the name of the DLL whether its a release or debug version
DLLFLAG=

endif

# Object directory
OBJDIR= obj

# Binary directory
BINDIR= bin

# Library directory
LIBDIR= ../common/vscphelper/lib/$(BUILDOS)/$(BUILDTYPE)

# Remove path from .c files, rename to .o files and add object directory
OBJECTS= $(addprefix $(OBJDIR)/,$(notdir $(SOURCES:%.c=%.o)))

# All dependency files
DEPFILES= $(OBJECTS:%.o=%.d)

# DLLS
DLLS=

ifeq ($(OS),Windows_NT)

# DLLs
DLLS= $(BINDIR)/libcrypto-1_1-x64.dll \
	$(BINDIR)/libexpat$(DLLFLAG).dll \
	$(BINDIR)/libssl-1_1-x64.dll \
	$(BINDIR)/libvscphelper15.dll \
	$(BINDIR)/pthreadVCE3$(DLLFLAG).dll

endif

################################################################################
# Tools
################################################################################

# Compiler
CC= gcc

# Linker
LD= gcc

# Remove file(s)
REMOVE= rm

# Make directory
MKDIR= mkdir

# Copy file(s)
COPY= cp

################################################################################
# Targets
################################################################################

help:
	@echo "********"
	@echo "* HELP *"
	@echo "********"
	@echo ""
	@echo "Targets:"
	@echo "debug   - Build binary (debug)"
	@echo "release - Build binary (release)"
	@echo "depend  - Generate dependency files"
	@echo "clean   - Remove object and binary files"
	@echo "objsize - Show object sizes"
	@echo "help    - This help is shown"
	@echo ""
	
debug: $(BINDIR)/$(BIN).exe $(DLLS)
	@echo "Finished."

release: $(BINDIR)/$(BIN).exe $(DLLS)
	@echo "Finished."

clean:
	@echo "Cleaning files ..."
	@$(REMOVE) -Rf $(BINDIR) $(OBJDIR) 2> /dev/null
	@echo "Finished."
	
objsize:
	@echo ".text       : normal program code"
	@echo ".bootloader : bootloader program code"
	@echo ".data       : initialized data"
	@echo ".bss        : data initialized by 0"
	@echo ".noinit     : not initialized data"
	@echo "Flash  = .text + .bootloader + .data"
	@echo "SRAM   = .data + .bss + .noinit"
	@echo "EEPROM = .eeprom"
	@size -d $(OBJDIR)/*.o
	
depend: $(DEPFILES)
	@echo "Finished."

.PHONY: help clean

# Include dependency files only in case of target 'debug' or 'release'
ifeq ($(MAKECMDGOALS),debug)
-include $(DEPFILES)
endif
ifeq ($(MAKECMDGOALS),release)
-include $(DEPFILES)
endif

################################################################################
# Rules
################################################################################
	
# Common rule to create object files from source files
$(OBJDIR)/%.o: %.c
	@echo "Compiling" $<
	@$(CC) -c $(CFLAGS) $(PREPROC) $(INCLUDES) $< -o $(OBJDIR)/$(@F) 2>&1
	
# Common rule to create dependency files from source files
$(OBJDIR)/%.d: %.c
	@echo "Create dependencies of" $<
	@$(CC) $(PREPROC) $(INCLUDES) -MM $< | sed 's#^\(.*:\)#./$(OBJDIR)/\1#' > $(OBJDIR)/$(@F)

$(DEPFILES): | $(OBJDIR)

$(OBJECTS): | $(OBJDIR) $(BINDIR)

# Create directory for object and dependency files
$(OBJDIR):
	@$(MKDIR) -p $(OBJDIR)

# Create directory for binary
$(BINDIR):
	@$(MKDIR) -p $(BINDIR)

# Link all objects together and build the binary
$(BINDIR)/$(BIN).exe: $(DEPFILES) $(OBJECTS)
	@echo "Linking ..."
	@$(LD) $(OBJECTS) $(LDFLAGS) $(LIBPATH) $(LIBRARIES) -o $(BINDIR)/$(BIN)

# Copy all necessary windows DLLs to the binary folder
$(BINDIR)/%.dll: $(LIBDIR)/%.dll
	@echo "Copy" $< "to ./"$(BINDIR)"/"
	@$(COPY) $< ./$(BINDIR)
