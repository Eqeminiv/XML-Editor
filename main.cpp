#include "UI.h"
#include <iostream>


int main()
{
	try
	{
		UI::Run();
	}
	catch (const std::exception & error)
	{
		std::cout << error.what();
	}
	catch (...)
	{
		std::cout << "Unexpected error" << std::endl;
	}

	return 0;
}