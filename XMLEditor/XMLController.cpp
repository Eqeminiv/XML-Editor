#include "XMLController.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <exception>




XMLController::XMLController()
{
	std::string path = "";
	while (!std::filesystem::exists(path) || !XMLController::isXML(path))
	{
		std::cout << "Path input: " << std::endl;
		std::cin >> path;
	}
	this->path = path;

	std::fstream file;
	file.open(path, std::ios::in);
	this->fileContent = readFile(file);
	file.close();
	std::stack<XMLLine> nodeStack;
	

	
	std::string temp;
	std::istringstream tempIstring(fileContent);
	std::cout << fileContent << std::endl;
	while (std::getline(tempIstring, temp))
	{
		XMLLine xmlLine = XMLLine(temp);
		nodeStack.push(xmlLine);
		
		try //where should start?
		{
			if (nodeStack.top().getIsEnd())
			{
				if (nodeStack.top().getIsStart())
					nodeStack.pop();
				else
				{
					XMLLine tempXMLLine = nodeStack.top();
					nodeStack.pop();
					if (tempXMLLine.getName() == nodeStack.top().getName())
						nodeStack.pop();
					else
					{
						//catch exception
						throw std::runtime_error("Incorrect XML\n");
					}
				}
			}
			this->nodeList.push_back(xmlLine);
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
	}
}

XMLController::~XMLController()
{
	
}

bool XMLController::isXML(std::string path) 
{
	std::string tempPath = path.substr(path.find_last_of(".") + 1);
	for (int i = 0; i < tempPath.length(); i++)
		tempPath[i] = toupper(tempPath[i]);
	if (tempPath == "XML")
		return true;
	return false;

}

bool XMLController::isXMLValid()
{
	return true;//todo
}


std::string XMLController::readFile(std::fstream& file)
{
	std::string temp;
	if (file.is_open())
	{
		std::getline(file, temp, '\0');
		return temp;
	}
	return "";
	
}
std::string XMLController::getPath()
{
	return path;
}

std::string XMLController::getFileContent()
{
	return fileContent;
}









