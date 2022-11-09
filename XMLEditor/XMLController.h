#pragma once
#include "XMLTag.h"
#include "XMLComponent.h"
#include <string>
#include <vector>
#include <fstream>
#include <memory>





class XMLController
{
private:
	const std::string path;
	std::string fileContent;
	std::vector<XMLTag> nodeList;
	
	//XMLComponent* tree;
	std::shared_ptr<XMLComponent> tree;
	


public:
	XMLController(const std::string& path);
	std::string getPath() const;
	static bool isXML(const std::string& path);
	std::shared_ptr<XMLComponent> getTree();
	std::string readFile(std::fstream& file) const;
	std::string getFileContent() const;


};

