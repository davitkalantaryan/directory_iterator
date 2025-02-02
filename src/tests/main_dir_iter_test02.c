//
// file:			main_dir_iter_test01.cpp  
// path:			src/tests/main_dir_iter_test01.cpp  
// created on:		2023 Jan 10
// Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//

#include <directory_iterator/directory_iterator.h>
#include <cinternal/disable_compiler_warnings.h>
#include <stdio.h>
#include <string.h>
#include <cinternal/undisable_compiler_warnings.h>

static int DirIterFuncStatic(const char* a_sourceDirectory,void*, const DirIterFileData*) CPPUTILS_NOEXCEPT;

int main(int a_argc, char* a_argv[])
{
	if (a_argc < 2) {
		fprintf(stderr, "Directory to iterate is not provided\n");
		return 1;
	}

	IterateOverDirectoryFilesRecurse(a_argv[1], &DirIterFuncStatic, CPPUTILS_NULL);

	return 0;
}


static int DirIterFuncStatic(const char* a_sourceDirectory,void* a_pUd, const DirIterFileData* a_pData) CPPUTILS_NOEXCEPT
{
	uint32_t i = 0;
    CPPUTILS_STATIC_CAST(void,a_sourceDirectory);
    CPPUTILS_STATIC_CAST(void,a_pUd);
	for (; i < a_pData->deepness; ++i) {
		printf(" ");
	}
	printf("%s\n", a_pData->pFileName);
	if (strcmp(a_pData->pFileName, "finish") == 0) { return DIRITER_EXIT_ALL; }
	return 0;
}
