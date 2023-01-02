//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CWebFontDownloader
#define PDFTRON_H_CWebFontDownloader

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>


struct TRN_WebFontDownloader_tag;
typedef struct TRN_WebFontDownloader_tag* TRN_WebFontDownloader;


/* methods: */
TRN_API TRN_WebFontDownloaderIsAvailable(TRN_Bool* result);
TRN_API TRN_WebFontDownloaderEnableDownloads();
TRN_API TRN_WebFontDownloaderDisableDownloads();
TRN_API TRN_WebFontDownloaderPreCacheAsync();
TRN_API TRN_WebFontDownloaderClearCache();
TRN_API TRN_WebFontDownloaderSetCustomWebFontURL(TRN_UString url);



#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CWebFontDownloader */