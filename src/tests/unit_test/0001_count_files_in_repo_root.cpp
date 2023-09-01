//
// repo:			directory_iterator
// file:			0001_count_files_in_repo_root.cpp
// path:			${repositoryRoot}/src/tests/unit_test/0001_count_files_in_repo_root.cpp
// created on:		2023 Sep 01
//

#include <directory_iterator/directory_iterator.h>
#include <cinternal/unit_test.h>


static int DirIterFuncStatic(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CPPUTILS_NOEXCEPT;


TEST(f_0001_count_files_in_repo_root, t_0001)
{
	int nFilesCount = 0;
	// we assume that the directory is ${repositoryRoot}/sys/win_x64/Debug/test
	IterateOverDirectoryFilesNoRecurse("../../../..", &DirIterFuncStatic, &nFilesCount);
	EXPECT_EQ(nFilesCount, 17);

}


static int DirIterFuncStatic(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CPPUTILS_NOEXCEPT
{
	int* pnFilesCount = (int*)a_pUd;
	(void)a_sourceDirectory;
	(void)a_pData;
	++(*pnFilesCount);
	return 0;
}
