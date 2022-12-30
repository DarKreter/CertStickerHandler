//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CVerificationOptions
#define PDFTRON_H_CVerificationOptions

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>


struct TRN_VerificationOptions_tag;
typedef struct TRN_VerificationOptions_tag* TRN_VerificationOptions;

/* enums:  */
enum TRN_VerificationOptions_SecurityLevel {
	e_VerificationOptions_compatibility_and_archiving = 0,
	e_VerificationOptions_maximum = 1
};
enum TRN_VerificationOptions_TimeMode {
	e_VerificationOptions_signing = 0,
	e_VerificationOptions_timestamp = 1,
	e_VerificationOptions_current = 2
};

/* methods: */
TRN_API TRN_VerificationOptionsCreate(enum TRN_VerificationOptions_SecurityLevel in_level, TRN_VerificationOptions* result);
TRN_API TRN_VerificationOptionsAddTrustedCertificate(TRN_VerificationOptions self, const TRN_UInt8* in_binary_DER_certificate_buf, const size_t in_buf_size);
TRN_API TRN_VerificationOptionsRemoveTrustedCertificate(TRN_VerificationOptions self, const TRN_UInt8* in_binary_DER_certificate_buf, const size_t in_buf_size);
TRN_API TRN_VerificationOptionsEnableModificationVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableDigestVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableTrustVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);

TRN_API TRN_VerificationOptionsDestroy(TRN_VerificationOptions self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CVerificationOptions */