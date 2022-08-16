#pragma once
#include <string>

class Attribute
{
private:
	std::string name, value;

public:
	Attribute(const std::string& name, const std::string& value);
	~Attribute();
	std::string getName();
	std::string getValue();


};