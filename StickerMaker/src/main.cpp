#include <PDF/PDFNet.h>
#include <PDF/PDFDoc.h>
#include <PDF/ElementBuilder.h>
#include <PDF/ElementWriter.h>
#include <PDF/ElementReader.h>
#include <PDF/Image.h>
#include <Filters/MappedFile.h>
#include <Filters/FilterReader.h>
#include <SDF/ObjSet.h>

#include <Entertainment.h>
#include <FilesManagment.h>

#include <iostream>
#include <iterator>
#include <algorithm>
#include <windows.h>
#include <direct.h>

using namespace std;
using namespace pdftron;
using namespace Common;
using namespace SDF;
using namespace PDF;

void PasteStamp(wstring pdfName);

int main(int argc, char* argv[])
{
	PDFNet::Initialize();
	system("cls");
	system("pause");

	wstring path = L"PDF\\";
	vector<wstring> files;

	fm::ReadDirectoryWS(path, files, { ".pdf" });

	try
	{
		fm::CreateDirectory("PDF-PODPISANE");

		for (auto& file : files)
		{
			PasteStamp(file);
			ent::ChangeColor(ent::darkBlue);	 cout << file << "\t";
			ent::ChangeColor(ent::lime);		 cout << "DONE" << endl;
		}

	}
	catch (Common::Exception& e)
	{
		ent::ChangeColor(ent::red); cout << e << endl;
		system("pause");
	}
	catch (...)
	{
		ent::ChangeColor(ent::red); cout << "Unknown Exception" << endl;
		system("pause");

	}
	PDFNet::Terminate();

	cout << "SUCCESS" << endl;
	system("pause");
	return 0;
}

void PasteStamp(wstring pdfName)
{
	// Relative path to the folder containing test files.
	wstring input_path = L"PDF/";
	wstring output_path = L"PDF-PODPISANE/";


	wstring inputName = input_path + pdfName;
	PDFDoc doc(inputName);

	ElementBuilder f;		// Used to build new Element objects
	ElementWriter writer;	// Used to write Elements to the page	

	Page page = doc.GetPage(1);	// Start a new page
	writer.Begin(page);		// Begin writing to this page

	// ----------------------------------------------------------
	// Add JPEG image to the output file
	PDF::Image img = PDF::Image::Create(doc, "Sticker.jpg");
	Element element = f.CreateImage(img, 425, 41, img.GetImageWidth() * 0.30, img.GetImageHeight() * 0.30);
	writer.WritePlacedElement(element);


	writer.End();	// Finish writing to the page

	// ----------------------------------------------------------

	wstring outputName = output_path + pdfName;

	doc.Save(outputName, SDFDoc::e_linearized, 0);

}