#!/bin/bash -f

REPLACEME_SV_SPECIAL_COMPILER_SCRIPT

export CC=REPLACEME_CC
export CXX=REPLACEME_CXX

CompileScripts/tcl-REPLACEME_SV_PLATFORM-generic.sh REPLACEME_SV_TCL_VERSION REPLACEME_SV_COMPILER_BIN_DIR
