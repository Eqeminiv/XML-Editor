#pragma once
#include "Attribute.h"
#include <string>
#include <vector>


class XMLTag //XMLTag
{
private:
	std::string name;
	std::string value;
	std::vector<Attribute> attributeVector;
	bool isStart, isEnd; //leaf if both 1 otherwise composite
	void divideLine(const std::string& content);

	


public:
	XMLTag();
	XMLTag(const XMLTag &xmlNode);
	XMLTag(std::string content);
	~XMLTag();
	void showLine();
	void populateVector();
	std::string getName() const;
	std::string getValue() const;
	bool getIsStart() const;
	bool getIsEnd() const;
	XMLTag operator=(const XMLTag & rightXml);

	
};