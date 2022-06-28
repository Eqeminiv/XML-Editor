#pragma once
#include "XMLLine.h"
#include <string>
#include <vector>
#include <stack>
#include <fstream>





class XMLController
{
private:
	std::string path;
	std::string fileContent;
	std::vector<XMLLine> nodeList;
	


public:
	XMLController();
	~XMLController();
	std::string getPath();
	bool isXML(std::string path);
	bool isXMLValid();
	
	std::string readFile(std::fstream& file);
	std::string getFileContent();


};

