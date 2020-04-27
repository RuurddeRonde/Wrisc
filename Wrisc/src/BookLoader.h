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
		tinyxml2::XMLDocument xmlDoc;
		tinyxml2::XMLError eResult = xmlDoc.LoadFile(path.c_str());
		//XMLCheckResult(eResult);
		tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr)
		{
			//error
		}

		const char * temp = nullptr;
		tinyxml2::XMLElement * pElement = pRoot->FirstChildElement("path");
		temp = pElement->FirstChild()->Value();
		if (temp == nullptr)
		{
			//error
		}
		std::string sPath = temp;

		pElement = pRoot->FirstChildElement("AlineaFont");
		temp = pElement->FirstChild()->Value();
		if (temp == nullptr)
		{
			//error
		}
		std::string sAlFont = temp;

		pElement = pRoot->FirstChildElement("h1Font");
		temp = pElement->FirstChild()->Value();
		if (temp == nullptr)
		{
			//error
		}
		std::string sh1Font = temp;

		pElement = pRoot->FirstChildElement("h2Font");
		temp = pElement->FirstChild()->Value();
		if (temp == nullptr)
		{
			//error
		}
		std::string sh2Font = temp;

		int tempInt;
		pElement = pRoot->FirstChildElement("AlineaFontSize");
		tempInt = pElement->IntText();
		if (tempInt == 0)
		{
			tempInt = 11;
		}
		int alineaFontSize = tempInt;

		pElement = pRoot->FirstChildElement("h1FontSize");
		tempInt = pElement->IntText();
		if (tempInt == 0)
		{
			tempInt = 11;
		}
		int h1FontSize = tempInt;

		pElement = pRoot->FirstChildElement("h2FontSize");
		tempInt = pElement->IntText();
		if (tempInt == 0)
		{
			tempInt = 11;
		}
		int h2FontSize = tempInt;

		Book b(path, alineaFontSize, h1FontSize, h2FontSize);

		//loop chapters

		pElement = pRoot->FirstChildElement("chapter");
		while (pElement != nullptr)
		{
			std::string temph1 = pElement->FirstChildElement("h1")->FirstChild()->Value();
			std::string temph2 = pElement->FirstChildElement("h2")->FirstChild()->Value();
			std::string temptext = pElement->FirstChildElement("text")->FirstChild()->Value();
			b.newChapter(temph1, temph2, temptext);
			pElement = pElement->NextSiblingElement("chapter");
		}
		return b;
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