//
// file:			directory_iterator_unix.c  
// path:			src/core/diriter/irectory_iterator_unix.c  
// created on:		2023 Jan 10
// Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//


#include <directory_iterator/export_symbols.h>

#ifndef _WIN32

#include <directory_iterator/directory_iterator.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>


CINTERNAL_BEGIN_C


// https://stackoverflow.com/questions/61012825/how-to-identify-which-entries-are-files-and-which-are-directories-in-c

static void WinDataToClbkData(DirIterFileData* a_pClbk, const struct dirent* a_pSysData)
{
	a_pClbk->isDir = (a_pWinData->dwFileAttributes& FILE_ATTRIBUTE_DIRECTORY)? CINTERNAL_STATIC_CAST(uint64_t,1): CINTERNAL_STATIC_CAST(uint64_t, 0);
	a_pClbk->fileAttributes = CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->dwFileAttributes);
	a_pClbk->creationTimeIn100Ms = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftCreationTime.dwHighDateTime)<<32)& 
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftCreationTime.dwLowDateTime);
	a_pClbk->lastAccessTimeIn100Ms = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastAccessTime.dwHighDateTime) << 32) &
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastAccessTime.dwLowDateTime);
	a_pClbk->lastWriteTimeIn100Ms = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastWriteTime.dwHighDateTime) << 32) &
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastWriteTime.dwLowDateTime);
	a_pClbk->fileSize = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->nFileSizeHigh) << 32) &
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->nFileSizeLow);
	a_pClbk->pFileName = a_pWinData->cFileName;
	a_pClbk->pAlternateFileName = a_pWinData->cAlternateFileName;
}


DIRITER_EXPORT void IterateOverDirectoryFiles(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud)
{
	int nReadDirResult;
	DIR* pDir;
	struct dirent* pResult;
	struct dirent inpBuffer;
	
	pDir = opendir(a_sourceDirectory);
	
	if(!pDir){return;}
	
	nReadDirResult = readdir_r(pDir,&inpBuffer,&pResult);
	assert(nReadDirResult==0);
	while(pResult){
		if (pResult->d_name[0] == '.') {
			if ((pResult->d_name[1] == 0) || ((pResult->d_name[1] == '.') && (pResult->d_name[2] == 0))) { continue; }
		}
	}
}


CINTERNAL_END_C


#endif  //  #ifdef _WIN32
