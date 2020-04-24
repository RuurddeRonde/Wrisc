#pragma once
#include "book.h"
class AppManager
{
public:
	static AppManager& getInstance()
	{
		static AppManager    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	AppManager(AppManager const&) = delete;
	void operator=(AppManager const&) = delete;

private:

	AppManager() {}
};
