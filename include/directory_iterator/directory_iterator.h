//
// file:			directory_iterator.h
// path:			include/directory_iterator/directory_iterator.h
// created on:		2023 Jan 10
// created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//

#ifndef DIRECTORY_ITERATOR_INCLUDE_DIRECTORY_ITERATOR_DIRECTORY_ITERATOR_H
#define DIRECTORY_ITERATOR_INCLUDE_DIRECTORY_ITERATOR_DIRECTORY_ITERATOR_H

#include <directory_iterator/export_symbols.h>
#include <stdint.h>

CINTERNAL_BEGIN_C


// see: https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa
typedef struct SDirIterFileData {
	uint64_t	isDir : 1;
	uint64_t	reserved01 : 63;
	uint64_t	fileAttributes;			// see: https://learn.microsoft.com/en-us/windows/win32/fileio/file-attribute-constants
	uint64_t	creationTimeIn100Ms;	// see: https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime
	uint64_t	lastAccessTimeIn100Ms;	// see: https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime
	uint64_t	lastWriteTimeIn100Ms;	// see: https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime
	uint64_t	fileSize;
	const char* pFileName;
	const char* pAlternateFileName;
}DirIterFileData;

typedef int		(*TypeDirIterFunc)(const char*,void*, const DirIterFileData*);

DIRITER_EXPORT void IterateOverDirectoryFiles(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud);

CINTERNAL_END_C


#endif  // #ifndef DIRECTORY_ITERATOR_INCLUDE_DIRECTORY_ITERATOR_DIRECTORY_ITERATOR_H
