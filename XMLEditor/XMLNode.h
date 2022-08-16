#pragma once
#include "XMLTag.h"
#include <vector>

class XMLNode
{
private:
	XMLTag info;
	XMLNode*parent;
	std::vector<XMLNode*> children;
	int level;

public:
	XMLNode(const XMLTag &xmlNode);
	~XMLNode();
	XMLTag getXMLTag();
	void findChildren(const std::vector<XMLTag>& nodeList, const int startPoint);

};