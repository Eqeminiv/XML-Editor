#include "Attribute.h"

Attribute::Attribute(const std::string& name, const std::string& value)
{
	this->name = name;
	this->value = value;
}

Attribute::~Attribute()
{

}

std::string Attribute::getName()
{
	return name;
}

std::string Attribute::getValue()
{
	return value;
}