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
	const char* pFileName;
	const void* pSystemData;
}DirIterFileData;

typedef int		(*TypeDirIterFunc)(const char*,void*, const DirIterFileData*);

DIRITER_EXPORT void IterateOverDirectoryFilesNoRecurse(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud);

CINTERNAL_END_C


#endif  // #ifndef DIRECTORY_ITERATOR_INCLUDE_DIRECTORY_ITERATOR_DIRECTORY_ITERATOR_H
