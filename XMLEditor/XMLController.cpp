#include "XMLController.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <exception>
#include <stack>




XMLController::XMLController(const std::string& _path) : path(_path)
{
	std::fstream file;
	file.open(path, std::ios::in);
	fileContent = readFile(file);
	file.close();
	tree = new XMLComposite;

	std::string temp;
	std::istringstream tempIstring(fileContent);
	std::cout << fileContent << std::endl;

	tree->SetParent(nullptr);

	XMLComponent* currXMLComponent = tree;

	while (std::getline(tempIstring, temp))
	{
		XMLTag xmlNode = XMLTag(temp);
		this->nodeList.push_back(xmlNode);

		if (xmlNode.getIsEnd())
		{
			if (xmlNode.getIsStart())
			{
				XMLComponent* xmlLeaf = new XMLLeaf;
				xmlLeaf->SetXMLTag(xmlNode);
				currXMLComponent->Add(xmlLeaf);
			}
			else
			{
				XMLTag tempXMLTag = xmlNode;
				if (currXMLComponent->GetInfo().getName() == xmlNode.getName())
				{
					currXMLComponent = currXMLComponent->GetParent();
				}

				else
				{
					//catch exception
					throw std::runtime_error("Incorrect XML\n");
				}
			}
		}
		else
		{
			XMLComponent* xmlComponent = new XMLComposite;
			xmlComponent->SetXMLTag(xmlNode);
			currXMLComponent->Add(xmlComponent);
			currXMLComponent = xmlComponent;
		}

			
			
	}
	tree->ShowAll(0);

	delete tree;
	
}


bool XMLController::isXML(const std::string& path) 
{
	std::string tempPath = path.substr(path.find_last_of(".") + 1);
	std::string xml = "XML";
	if (_stricmp(tempPath.c_str(), xml.c_str()) == 0)
		return true;
	return false;

}

std::string XMLController::readFile(std::fstream& file) const
{
	std::string temp;
	if (file.is_open())
	{
		std::getline(file, temp, '\0');
		return temp;
	}
	return "";
	
}
std::string XMLController::getPath() const
{
	return path;
}

std::string XMLController::getFileContent() const
{
	return fileContent;
}









