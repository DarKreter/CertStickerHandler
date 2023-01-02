#include <LicenseKey.h>

#include "Filters/FilterReader.h"
#include "Filters/MappedFile.h"
#include "PDF/ElementBuilder.h"
#include "PDF/ElementReader.h"
#include "PDF/ElementWriter.h"
#include "PDF/Image.h"
#include "PDF/PDFDoc.h"
#include "PDF/PDFNet.h"
#include "SDF/ObjSet.h"

#include "Entertainment.hpp"
#include "FilesManagment.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

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

using namespace std;
using namespace pdftron;
using namespace Common;
using namespace SDF;
using namespace PDF;
using ent::Format_t;

void PasteStamp(string pdfName);

int main(int argc, char* argv[])
{
    Format_t errorColor(Format_t::Color::red);
    Format_t successColor(Format_t::Color::green);
    Format_t dataColor(Format_t::Color::blue);

    PDFNet::Initialize(LicenseKey);
    // system("clear");
    cin.get();

    string path = "PDF/";
    vector<string> files;

    fm::ReadDirectory(path, files, {"*.pdf"});

    try {
        fm::CreateDirectory("PDF-PODPISANE");

        for(auto& file : files) {
            PasteStamp(file);
            cout << dataColor << file << "\t" << successColor << "DONE" << endl;
        }
    }
    catch(Common::Exception& e) {
        cout << errorColor << e << endl;
        cin.get();
    }
    catch(...) {
        cout << errorColor << "Unknown Exception" << endl;
        cin.get();
    }
    PDFNet::Terminate();

    cout << successColor << "SUCCESS" << endl;
    cin.get();
    return 0;
}

void PasteStamp(string pdfName)
{
    size_t idx = pdfName.find_last_of('/');
    if(idx != string::npos)
        pdfName = pdfName.substr(idx + 1);

    // Relative path to the folder containing test files.
    string input_path = "PDF/";
    string output_path = "PDF-PODPISANE/";

    string inputName = input_path + pdfName;
    PDFDoc doc(inputName);

    ElementBuilder f;     // Used to build new Element objects
    ElementWriter writer; // Used to write Elements to the page

    Page page = doc.GetPage(1); // Start a new page
    writer.Begin(page);         // Begin writing to this page

    // ----------------------------------------------------------
    // Add JPEG image to the output file
    PDF::Image img = PDF::Image::Create(doc, "Sticker.jpg");
    Element element =
        f.CreateImage(img, 425, 41, img.GetImageWidth() * 0.30, img.GetImageHeight() * 0.30);
    writer.WritePlacedElement(element);

    writer.End(); // Finish writing to the page

    // ----------------------------------------------------------

    string outputName = output_path + pdfName;

    doc.Save(outputName, SDFDoc::e_linearized, 0);
}