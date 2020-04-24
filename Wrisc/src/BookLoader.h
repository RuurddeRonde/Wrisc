#pragma once
#include "Book.h"
#include "tinyxml2.h"
#include <string>
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

class BookLoader
{
public:
	static Book LoadBook(std::string path)
	{
	}
	static bool SaveBook(Book* book)
	{
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLNode* root = doc.NewElement("book");
		doc.InsertFirstChild(root);

		//path if needed
		tinyxml2::XMLElement* Element = doc.NewElement("path");
		Element->SetText(book->settings.path.c_str());
		root->InsertEndChild(Element);

		//font sizes
		Element = doc.NewElement("AlineaFontSize");
		Element->SetText(book->settings.AlineaFontSize);
		root->InsertEndChild(Element);

		Element = doc.NewElement("h1FontSize");
		Element->SetText(book->settings.h1fontsize);
		root->InsertEndChild(Element);

		Element = doc.NewElement("h2FontSize");
		Element->SetText(book->settings.h2fontsize);
		root->InsertEndChild(Element);


		//fonts
		Element = doc.NewElement("AlineaFont");
		Element->SetText(book->settings.Alineafont.c_str());
		root->InsertEndChild(Element);

		Element = doc.NewElement("h1Font");
		Element->SetText(book->settings.h1font.c_str());
		root->InsertEndChild(Element);

		Element = doc.NewElement("h2Font");
		Element->SetText(book->settings.h2font.c_str());
		root->InsertEndChild(Element);


		for (auto i = 0; i < book->chapters.size(); i++)
		{
			tinyxml2::XMLElement* celem = doc.NewElement("chapter");
			root->InsertEndChild(celem);

			Element = doc.NewElement("h1");
			Element->SetText(book->chapters[i].h1.c_str());
			celem->InsertEndChild(Element);
			Element = doc.NewElement("h2");
			Element->SetText(book->chapters[i].h2.c_str());
			celem->InsertEndChild(Element);
			Element = doc.NewElement("text");
			Element->SetText(book->chapters[i].text.c_str());
			celem->InsertEndChild(Element);
		}

		tinyxml2::XMLError eResult = doc.SaveFile("SavedData.book");
		XMLCheckResult(eResult);
		return true;
	}
private:
};

/*
TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
	TiXmlElement * element = new TiXmlElement( "Hello" );
	TiXmlText * text = new TiXmlText( "World" );
	element->LinkEndChild( text );
	doc.LinkEndChild( decl );
	doc.LinkEndChild( element );
	doc.SaveFile( "madeByHand.xml" );
*/