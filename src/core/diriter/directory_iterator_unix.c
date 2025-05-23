//
// file:			directory_iterator_unix.c  
// path:			src/core/diriter/irectory_iterator_unix.c  
// created on:		2023 Jan 10
// Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//


#include <directory_iterator/export_symbols.h>

#ifndef _WIN32

#include <directory_iterator/directory_iterator.h>
#include <cinternal/disable_compiler_warnings.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>
#include <cinternal/undisable_compiler_warnings.h>


CPPUTILS_BEGIN_C


// https://stackoverflow.com/questions/61012825/how-to-identify-which-entries-are-files-and-which-are-directories-in-c

static void SysDataToClbkData(DirIterFileData* a_pClbk, const struct dirent* a_pSysData)
{
	a_pClbk->isDir = (a_pSysData->d_type & DT_DIR)? CPPUTILS_STATIC_CAST(uint64_t,1): CPPUTILS_STATIC_CAST(uint64_t, 0);
	a_pClbk->pFileName = a_pSysData->d_name;
	a_pClbk->pSystemData = CPPUTILS_STATIC_CAST(const void*, a_pSysData);
}


DIRITER_EXPORT void IterateOverDirectoryFilesNoRecurse(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud)
{
	DIR* pDir = opendir(a_sourceDirectory);
	
	if(pDir){
        int nReturnFromCallback;
		struct dirent* pResult;
		DirIterFileData		aClbkData;
        pResult = readdir(pDir);  // readdir_r is deprecated. See: https://man7.org/linux/man-pages/man3/readdir.3.html
		while(pResult){			
			SysDataToClbkData(&aClbkData, pResult);
			
			nReturnFromCallback = (*a_callback)(a_sourceDirectory,a_ud, &aClbkData);
			if (nReturnFromCallback) { break; }
			
            pResult = readdir(pDir);
		}
		
		closedir(pDir);
	}
}


CPPUTILS_END_C


#endif  //  #ifdef _WIN32
