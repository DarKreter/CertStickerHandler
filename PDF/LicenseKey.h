//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef H_LICENSE_KEY
#define H_LICENSE_KEY

namespace pdftron {
// Uncomment the line below and replace YOUR_PDFTRON_LICENSE_KEY with your key.
#define LicenseKey "demo:1672419740504:7d7d69210300000000dfa92585cc4bbbecf02bc2af7681e19893020c5d"
#ifndef LicenseKey
#error                                                                                             \
    "Please enter your license key by defining the LicenseKey macro in Samples/LicenseKey/CPP/LicenseKey.h. If you do not have a license key, please go to https://www.pdftron.com/pws/get-key to obtain a demo license or https://www.pdftron.com/form/contact-sales to obtain a production key."
#endif
} // namespace pdftron

#endif
