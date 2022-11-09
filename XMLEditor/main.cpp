#include "XMLController.h"
#include <iostream>
#include <filesystem>


int main()
{

	try
	{
		std::string path;
		while (!std::filesystem::exists(path) || !XMLController::isXML(path))
		{
			std::cout << "Path input: " << std::endl;
			std::cin >> path;
		}
		XMLController controller(path);
		//controller.getTree().get().
	}
	/*std::string test = "  <Agenda type=\"gardening\">";
	std::regex reg("<\\w* tr");
	std::smatch results;
	
	
	if (std::regex_search(test, wynik, reg))
	{
		std::cout << results[0];
		
	}*/
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