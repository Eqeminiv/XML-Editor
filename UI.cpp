#include "UI.h"
#include <iostream>
#include <filesystem>
#include <exception>

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
	enum class Choice : int { Move = 1, Delete = 2, Show = 3, SaveAs = 4, Load = 5, Exit = 9};
	Choice choice = Choice::Move;
	int choiceInput;
	while (choice != Choice::Exit)
	{
		std::cout << std::endl << "Options: " << std::endl << "(1) Move node" << std::endl << "(2) Delete node" << std::endl << "(3) Show XML" << std::endl
			<< "(4) Save as" << std::endl << "(5) Load XML" << std::endl << "(9) Exit" << std::endl;
		std::cin >> choiceInput;
		choice = (Choice)choiceInput;
		switch (choice)
		{
		case Choice::Move:
		{
			std::string from, to;
			std::cout << "Enter name of node you want to move: ";
			std::cin >> from;
			std::cout << "Enter name of the target node: ";
			std::cin >> to;
			try
			{
				controller.MoveNode(from, to);
			}
			catch (const std::exception& error)
			{
				std::cout << error.what();
			}
			break;
		}
		case Choice::Delete:
		{
			std::string nodeName;
			std::cout << "Enter name of node you want to remove: ";
			std::cin >> nodeName;
			try
			{
				controller.RemoveNode(nodeName);
			}
			catch(const std::exception& error)
			{
				std::cout << error.what();
			}
			break;
		}
		case Choice::Show:
		{
			int level;
			std::cout << "Enter maximum number of levels you want to be showed: ";
			std::cin >> level;
			controller.ShowXML(level);
			break;
		}
		case Choice::SaveAs:
		{
			controller.SaveFile(true);
			break;
		}
		case Choice::Load:
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
		case Choice::Exit:
			break;
		}
	}
}