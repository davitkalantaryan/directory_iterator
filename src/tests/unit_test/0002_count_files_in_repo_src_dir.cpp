//
// repo:			directory_iterator
// file:			0002_count_files_in_repo_src_dir.cpp
// path:			${repositoryRoot}/src/tests/unit_test/0002_count_files_in_repo_src_dir.cpp
// created on:		2023 Sep 01
//

#include <directory_iterator/directory_iterator.h>
#include <cinternal/unit_test.h>
#include <cinternal/disable_compiler_warnings.h>
#include <stdio.h>
#include <cinternal/undisable_compiler_warnings.h>


static int DirIterFuncStaticNoRecurse(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CPPUTILS_NOEXCEPT;
static int DirIterFuncStaticRecurse(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CPPUTILS_NOEXCEPT;


TEST(f_0002_count_files_in_repo_src_dir, t_0001)
{
	int nFilesCountNR = 0, nFilesCountR = 0;
	// we assume that the directory is ${repositoryRoot}/sys/win_x64/Debug/test
	IterateOverDirectoryFilesNoRecurse("../../../..", &DirIterFuncStaticNoRecurse, &nFilesCountNR);
	IterateOverDirectoryFilesRecurse("../../../..", &DirIterFuncStaticRecurse, &nFilesCountR);
	printf("nFilesCountNR=%d, nFilesCountR=%d\n", nFilesCountNR, nFilesCountR);
	EXPECT_EQ(nFilesCountNR, nFilesCountNR);

}


static int DirIterFuncStaticNoRecurse(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CPPUTILS_NOEXCEPT
{
	int* pnFilesCount = (int*)a_pUd;

	if (a_pData->pFileName[0] == '.') {
		if ((a_pData->pFileName[1] == 0) || ((a_pData->pFileName[1] == '.') && (a_pData->pFileName[2] == 0))) { return 0; }
	}

	if (a_pData->isDir) {
		char  vcStrFilePath[4096];
		snprintf_di(vcStrFilePath, 4095, "%s/%s", a_sourceDirectory, a_pData->pFileName);
		IterateOverDirectoryFilesNoRecurse(vcStrFilePath, &DirIterFuncStaticNoRecurse, a_pUd);
	}
	else {
		++(*pnFilesCount);
	}

	return 0;
}


static int DirIterFuncStaticRecurse(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CPPUTILS_NOEXCEPT
{
	int* pnFilesCount = (int*)a_pUd;
	(void)a_sourceDirectory;

	if (a_pData->pFileName[0] == '.') {
		if ((a_pData->pFileName[1] == 0) || ((a_pData->pFileName[1] == '.') && (a_pData->pFileName[2] == 0))) { return 0; }
	}

	if (!a_pData->isDir) {
		++(*pnFilesCount);
	}

	return 0;
}
