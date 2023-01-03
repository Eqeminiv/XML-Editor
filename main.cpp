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
		XMLController controller;
		controller.Init(path);
		controller.ShowXML(100);
		int choice = -1;
		while (choice != 9)
		{
			std::cout << std::endl << "Options: " << std::endl << "(1) Move node" << std::endl << "(2) Delete node" << std::endl << "(3) Show XML" << std::endl
				<< "(4) Save as" << std::endl << "(5) Load XML" << std::endl << "(9) Exit" << std::endl;
			std::cin >> choice;
			switch (choice)
			{
				case 1:
				{
					std::string from, to;
					std::cout << "Enter name of node you want to move: ";
					std::cin >> from;
					std::cout << "Enter name of the target node: ";
					std::cin >> to;
					controller.MoveNode(from, to);
					break;
				}
				case 2:
				{
					std::string nodeName;
					std::cout << "Enter name of node you want to remove: ";
					std::cin >> nodeName;
					controller.RemoveNode(nodeName);
					break;
				}
				case 3:
				{
					int level;
					std::cout << "Enter maximum number of levels you want to be showed: ";
					std::cin >> level;
					controller.ShowXML(level);
					break;
				}
				case 4:
				{
					controller.SaveFile(true);
					break;
				}
				case 5:
				{
					path = "";
					while (!std::filesystem::exists(path) || !XMLController::isXML(path))
					{
						std::cout << "Path input: " << std::endl;
						std::cin >> path;
					}
					controller.Init(path);
					break;
				}
				case 9:
					break;
			}
		}
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