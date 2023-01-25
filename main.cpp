#include "UI.h"
#include <iostream>


int main()
{

	try
	{
		UI ui;
		ui.Run();
	}

	catch (const std::exception & error)
	{
		std::cout << error.what();
		//do what?
	}
	catch (...)
	{
		std::cout << "Unexpected error" << std::endl;
	}
	
	
	
	return 0;
}