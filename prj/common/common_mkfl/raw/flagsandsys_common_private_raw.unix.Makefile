#
# repo:		    directory_iterator
# file:		    flagsandsys_common_private_pure.unix.Makefile
# created on:	    2023 Aug 30
# created by:	    Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	    This file can be only as include
#

mkfile_path		=  $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir		=  $(shell dirname $(mkfile_path))
include $(mkfile_dir)/../flagsandsys_common.unix.Makefile
COMMON_FLAGS	+= -I$(directoryIteratorRepoRoot)/src/include
