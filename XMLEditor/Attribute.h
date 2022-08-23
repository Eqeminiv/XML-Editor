#pragma once
#include <string>

class Attribute
{
private:
	//const having troubles with vector push_back on XMLTag
	std::string name;
	std::string value;

public:
	Attribute(const std::string& _name, const std::string& _value);	
	std::string getName() const;
	std::string getValue() const;
};