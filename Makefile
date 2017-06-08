build-all:

MAKEFILE_PREFIX=keyboardio/avr/libraries/Kaleidoscope-Plugin/build
UNAME_S := $(shell uname -s)

BOARD_HARDWARE_PATH ?= $(shell pwd)/hardware
include $(BOARD_HARDWARE_PATH)/$(MAKEFILE_PREFIX)/*.mk
