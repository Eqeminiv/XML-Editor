#pragma once
#include "Attribute.h"
#include <string>
#include <vector>


class XMLTag
{
private:
	std::string name;
	std::string value;
	std::vector<Attribute> attributeVector;
	bool isStart = false; 
	bool isEnd = false;
	void divideLine(const std::string& content);

public:
	XMLTag();
	XMLTag(std::string content);
	void showLine() const;
	void populateVector();
	void SwitchIsEnd();
	void AddRemoveClosingSlash();
	std::string getName() const;
	std::string getValue() const;
	std::vector<Attribute> getAttributeVector() const;
	std::string getAllAttributeVectorXMLFormatted() const;
	bool getIsStart() const;
	bool getIsEnd() const;
	bool operator==(const XMLTag& right) const;
};