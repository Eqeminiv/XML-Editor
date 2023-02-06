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
	std::string path;
	std::string fileContent;
	std::vector<XMLTag> nodeList;
	std::shared_ptr<XMLComponent> tree;

public:
	XMLController();
	void Init(const std::string& _path);
	std::string getPath() const;
	static bool isXML(const std::string& path);
	std::shared_ptr<XMLComponent> getTree();
	std::string readFile(std::fstream& file) const;
	std::string getFileContent() const;
	void ShowXML(const int level) const;
	void MoveNode(const std::string& from, const std::string& to);
	void RemoveNode(const std::string& nodeName);
	void SaveFile(const bool toSameFile);
	bool isStringOnlyWhiteSpace(const std::string& checkedString) const;
};

