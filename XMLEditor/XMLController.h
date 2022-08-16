#pragma once
#include "XMLTag.h"
#include "XMLComponent.h"
#include <string>
#include <vector>
#include <fstream>





class XMLController
{
private:
	std::string path;
	std::string fileContent;
	std::vector<XMLTag> nodeList;
	
	XMLComponent* tree;
	


public:
	XMLController(const std::string& path);
	~XMLController();
	std::string getPath();
	static bool isXML(const std::string& path);
	bool isXMLValid();
	
	std::string readFile(std::fstream& file);
	std::string getFileContent();


};

