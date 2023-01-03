#include "XMLController.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <exception>
#include <stack>
#include <memory>



XMLController::XMLController()
{

}

void XMLController::Init(const std::string& path)
{
	this->path = path;
	std::fstream file;
	file.open(path, std::ios::in);
	fileContent = readFile(file);
	file.close();

	//tree = new XMLComposite;
	tree = std::make_shared<XMLComposite>();

	std::string temp;
	std::istringstream tempIstring(fileContent);
	//std::cout << fileContent << std::endl;

	tree->SetParent(nullptr);
	
	std::shared_ptr<XMLComponent> currXMLComponent = tree;
	//XMLComponent* currXMLComponent = tree;


	while (std::getline(tempIstring, temp))
	{
		std::cout << temp << std::endl;
		XMLTag xmlNode = XMLTag(temp);
		this->nodeList.push_back(xmlNode);

		if (xmlNode.getIsEnd())
		{
			if (xmlNode.getIsStart())
			{
				std::shared_ptr<XMLLeaf> xmlLeaf = std::make_shared<XMLLeaf>();
				//XMLComponent* xmlLeaf = new XMLLeaf;
				xmlLeaf->SetXMLTag(xmlNode);
				currXMLComponent->Add(xmlLeaf);
			}
			else
			{
				XMLTag tempXMLTag = xmlNode;
				if (currXMLComponent->GetInfo().getName() == xmlNode.getName())
				{
					//currXMLComponent->GetInfo().showLine();
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
			//XMLComponent* xmlComponent = new XMLComposite;
			std::shared_ptr<XMLComponent> xmlComponent = std::make_shared<XMLComposite>();
			xmlComponent->SetXMLTag(xmlNode);
			currXMLComponent->Add(xmlComponent);
			currXMLComponent = xmlComponent;
		}

			
			
	}
	//tree->searchForNodeOnChildren("leaf")->Remove();
	//tree->searchForNodeOnChildren("Test")->Move(tree->searchForNodeOnChildren("lunch"));
	//tree->searchForNodeOnChildren("Activity")->Remove();
	//ShowXML(100);
	//delete tree;
	
}

bool XMLController::isXML(const std::string& path) 
{
	std::string tempPath = path.substr(path.find_last_of(".") + 1);
	std::string xml = "XML";
	if (_stricmp(tempPath.c_str(), xml.c_str()) == 0)
		return true;
	return false;

}

std::shared_ptr<XMLComponent> XMLController::getTree()
{
	return tree;
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

void XMLController::ShowXML(const int level) const
{
	std::cout << std::endl;
	tree->ShowAll(level);
}

void XMLController::MoveNode(const std::string from, const std::string to)
{
	tree->searchForNodeOnChildren(from)->Move(tree->searchForNodeOnChildren(to));
}

void XMLController::RemoveNode(const std::string nodeName)
{
	tree->searchForNodeOnChildren(nodeName)->Remove();
}

void XMLController::SaveFile(const bool toSameFile)
{
	std::streambuf* psbuf, * backup;
	std::ofstream filestr(path, std::ofstream::trunc);
	if (toSameFile)
	{
		backup = std::cout.rdbuf();
		psbuf = filestr.rdbuf();
		std::cout.rdbuf(psbuf);
		tree->ShowAll(100);
		std::cout.rdbuf(backup);
		filestr.close();
	}
	else
	{

	}

}









