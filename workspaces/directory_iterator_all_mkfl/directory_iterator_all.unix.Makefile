

targetName=simple_cpp_bcrypt_all

mkfile_path		=  $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir		=  $(shell dirname $(mkfile_path))

ifndef simpleCppBcryptRepositoryRoot
        simpleCppBcryptRepositoryRoot	:= $(shell curDir=`pwd` && cd $(mkfile_dir)/../.. && pwd && cd ${curDir})
endif


all:
	$(MAKE) -f $(simpleCppBcryptRepositoryRoot)/prj/tests/simplecppbcrypt_unit_test_mult/simplecppbcrypt_unit_test.unix.Makefile			&& \
	$(MAKE) -f $(simpleCppBcryptRepositoryRoot)/prj/tests/any_quick_test_mkfl/any_quick_test.unix.Makefile

.PHONY: clean
clean:
	$(MAKE) -f $(simpleCppBcryptRepositoryRoot)/prj/tests/simplecppbcrypt_unit_test_mult/simplecppbcrypt_unit_test.unix.Makefile clean
	$(MAKE) -f $(simpleCppBcryptRepositoryRoot)/prj/tests/any_quick_test_mkfl/any_quick_test.unix.Makefile clean
	
