#pragma once
#include <string>
#include <vector>



struct bookSettings
{
	std::string savelocation;
	std::string Alineafont;
	std::string h1Alineafont;
	std::string h2Alineafont;
	std::string h3Alineafont;
	int AlineaFontSize;
	int h1fontsize;
	int h2fontsize;
	int h3fontsize;
};

class Chapter
{
public:
	Chapter();
	~Chapter();

private:

};


class Book
{
public:
	Book(std::string name, std::string savePath, int alsize = 11, int h1s = 24, int h2s = 18, int h3s = 14)
	{
		settings.AlineaFontSize = alsize;
		settings.h1Alineafont = h1s;
		settings.h2Alineafont = h2s;
		settings.h3Alineafont = h3s;
		settings.savelocation = savePath;
	}
	~Book()
	{

		chapters.clear();
	}
	void newChapter()
	{
		chapters.push_back(Chapter());
	}

private:
	bookSettings settings;
	std::vector<Chapter> chapters;
};
