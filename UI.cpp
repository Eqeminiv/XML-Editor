#include "UI.h"
#include <iostream>
#include <filesystem>

void UI::Run()
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
	enum choices { Move = 1, Delete = 2, Show = 3, SaveAs = 4, Load = 5, Exit = 9};
	int choice = INT_MIN;
	while (choice != Exit)
	{
		std::cout << std::endl << "Options: " << std::endl << "(1) Move node" << std::endl << "(2) Delete node" << std::endl << "(3) Show XML" << std::endl
			<< "(4) Save as" << std::endl << "(5) Load XML" << std::endl << "(9) Exit" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case Move:
		{
			std::string from, to;
			std::cout << "Enter name of node you want to move: ";
			std::cin >> from;
			std::cout << "Enter name of the target node: ";
			std::cin >> to;
			controller.MoveNode(from, to);
			break;
		}
		case Delete:
		{
			std::string nodeName;
			std::cout << "Enter name of node you want to remove: ";
			std::cin >> nodeName;
			controller.RemoveNode(nodeName);
			break;
		}
		case Show:
		{
			int level;
			std::cout << "Enter maximum number of levels you want to be showed: ";
			std::cin >> level;
			controller.ShowXML(level);
			break;
		}
		case SaveAs:
		{
			controller.SaveFile(true);
			break;
		}
		case Load:
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
		case Exit:
			break;
		}
	}
}