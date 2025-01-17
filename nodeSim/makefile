# The MIT License (MIT)
# 
# Copyright (c) 2014 - 2025 Andreas Merkle
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
# Makefile for VSCP PC example
# Author: Andreas Merkle, http://www.blue-andi.de
#
################################################################################

################################################################################
# Configuration
################################################################################

# Software version
VERSION= 3.0.0

# Binary file name
BIN= vscpExamplePc

# General include directories
INCLUDES= -I. \
		-Ivscp_user \
		-I../common \
		-I../common/vscp-bootloader/src \
		-I../common/vscphelper \
		-I../common/vscp-framework/src \
		-I../common/vscp-framework/src/events \
		-I/usr/include

# Sources
SOURCES= main.c \
		eeprom.c \
		lamp_sim.c \
		temperature_sim.c \
		vscp_thread.c \
		vscp_user/vscp_action.c \
		vscp_user/vscp_app_reg.c \
		vscp_user/vscp_bl_adapter.c \
		vscp_user/vscp_portable.c \
		vscp_user/vscp_ps_access.c \
		vscp_user/vscp_tp_adapter.c \
		vscp_user/vscp_timer.c \
		vscp_user/dm_std_xml.c \
		vscp_user/dm_ext_xml.c \
		../common/pc/cmdLineParser.c \
		../common/pc/log.c \
		../common/pc/platform.c \
		../common/vscp-bootloder/src/crc16ccitt.c \
		../common/vscp-bootloder/src/vscp_bootloader.c \
		../common/vscp-framework/src/vscp_core.c \
		../common/vscp-framework/src/vscp_data_coding.c \
		../common/vscp-framework/src/vscp_dev_data.c \
		../common/vscp-framework/src/vscp_dm.c \
		../common/vscp-framework/src/vscp_dm_ng.c \
		../common/vscp-framework/src/vscp_logger.c \
		../common/vscp-framework/src/vscp_ps.c \
		../common/vscp-framework/src/vscp_transport.c \
		../common/vscp-framework/src/vscp_util.c \
		../common/vscp-framework/src/events/vscp_evt_alarm.c \
		../common/vscp-framework/src/events/vscp_evt_aol.c \
		../common/vscp-framework/src/events/vscp_evt_configuration.c \
		../common/vscp-framework/src/events/vscp_evt_control.c \
		../common/vscp-framework/src/events/vscp_evt_data.c \
		../common/vscp-framework/src/events/vscp_evt_diagnostic.c \
		../common/vscp-framework/src/events/vscp_evt_display.c \
		../common/vscp-framework/src/events/vscp_evt_error.c \
		../common/vscp-framework/src/events/vscp_evt_gnss.c \
		../common/vscp-framework/src/events/vscp_evt_information.c \
		../common/vscp-framework/src/events/vscp_evt_ir.c \
		../common/vscp-framework/src/events/vscp_evt_log.c \
		../common/vscp-framework/src/events/vscp_evt_measurement.c \
		../common/vscp-framework/src/events/vscp_evt_measurement32.c \
		../common/vscp-framework/src/events/vscp_evt_measurement64.c \
		../common/vscp-framework/src/events/vscp_evt_measurezone.c \
		../common/vscp-framework/src/events/vscp_evt_multimedia.c \
		../common/vscp-framework/src/events/vscp_evt_phone.c \
		../common/vscp-framework/src/events/vscp_evt_protocol.c \
		../common/vscp-framework/src/events/vscp_evt_security.c \
		../common/vscp-framework/src/events/vscp_evt_setvaluezone.c \
		../common/vscp-framework/src/events/vscp_evt_weather.c \
		../common/vscp-framework/src/events/vscp_evt_weather_forecast.c \
		../common/vscp-framework/src/events/vscp_evt_wireless.c

# Include all source pathes here like ../src1:../src2
VPATH= ../common:../common/vscphelper:../common/vscp-framework/src:../common/vscp-framework/src/events:vscp_user:../common/vscp-bootloader/src

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
LIBPATH= -L../common/vscphelper/lib/$(BUILDOS)/$(BUILDTYPE) \
		-L/usr/lib

# Libraries (-l...)
LIBRARIES= -lm -lvscphelper -lexpat

# Windows specific part
ifeq ($(OS),Windows_NT)
LIBRARIES+= -lws2_32
else
LIBRARIES+= -ldl -lpthread -lssl
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
LDFLAGS= -Wall -Wl,-Map,$(BINDIR)/$(BIN).map -Wl,--cref -Wl,--gc-sections

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
