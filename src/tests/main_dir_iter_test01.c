//
// file:			main_dir_iter_test01.cpp  
// path:			src/tests/main_dir_iter_test01.cpp  
// created on:		2023 Jan 10
// Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//


#include <directory_iterator/directory_iterator.h>
#include <stdio.h>


struct SDirIterData {
	int nDeepness;
};

static int DirIterFuncStatic(const char* a_sourceDirectory,void*, const DirIterFileData*) CINTERNAL_NOEXCEPT;

int main(int a_argc, char* a_argv[])
{
	struct SDirIterData aDt;
	aDt.nDeepness = 0;

	if (a_argc < 2) {
		fprintf(stderr, "Directory to iterate is not provided\n");
		return 1;
	}

	IterateOverDirectoryFilesNoRecurse(a_argv[1], &DirIterFuncStatic, &aDt);

	return 0;
}


static int DirIterFuncStatic(const char* a_sourceDirectory,void* a_pUd, const DirIterFileData* a_pData) CINTERNAL_NOEXCEPT
{
	struct SDirIterData* pDt = (struct SDirIterData*)a_pUd;
	int i = 0;
	for (; i < pDt->nDeepness; ++i) {
		printf(" ");
	}

	printf("%s\n", a_pData->pFileName);

	if (a_pData->isDir) {
		char  vcStrFilePath[4096];
		++(pDt->nDeepness);
		snprintf_di(vcStrFilePath, 4095, "%s/%s", a_sourceDirectory, a_pData->pFileName);
		IterateOverDirectoryFilesNoRecurse(vcStrFilePath, &DirIterFuncStatic, pDt);
		--(pDt->nDeepness);
	}

	return 0;
}