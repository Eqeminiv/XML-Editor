#include "Attribute.h"
#include <iostream>

Attribute::Attribute(const std::string& _name, const std::string& _value) : name(_name), value(_value) 
{

}

std::string Attribute::getName() const
{
	return name;
}

std::string Attribute::getValue() const
{
	return value;
}

std::string Attribute::getXMLFormatted() const
{
	return name + "=" + "\"" + this->value + "\"";
}

bool Attribute::operator==(const Attribute& right) const
{
	return (name == right.getName() && value == right.getValue());
}
