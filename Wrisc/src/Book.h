#pragma once
#include <string>
#include <vector>



struct bookSettings
{
	std::string Alineafont;
	std::string h1font;
	std::string h2font;
	std::string path;
	int AlineaFontSize;
	int h1fontsize;
	int h2fontsize;
};

class Chapter
{
public:
	Chapter() 
	{
		h1 = "The beginning";
		h2 = "It all starts here";
		text = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,\n when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
	}
	~Chapter() {}
	std::string h1;
	std::string h2;
	std::string text;
private:
};


class Book
{
public:
	Book(std::string name = "newBook",  int alsize = 11, int h1s = 24, int h2s = 18, int h3s = 14)
	{
		settings.AlineaFontSize = alsize;
		settings.h1fontsize = h1s;
		settings.h2fontsize = h2s;
		settings.path = name + ".xml";
		settings.Alineafont = "arial";
		settings.h1font = "arial";
		settings.h2font = "arial";
		chapterindex = 0;
		newChapter();
	}
	~Book()
	{
		chapters.clear();
	}
	void newChapter()
	{
		chapters.push_back(Chapter());
	}

	bookSettings settings;
	std::vector<Chapter> chapters;
	int chapterindex;
private:
};
