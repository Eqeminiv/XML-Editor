#include "XMLTag.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <stack>
#include <regex>


XMLTag::XMLTag()
{

}


XMLTag::XMLTag(std::string content)
{
	divideLine(content);
	if (isStart)
	{
		populateVector();
	}
}

void XMLTag::divideLine(const std::string& content)
{
	std::regex regForName("<[\\w-\\/]*");
	std::regex regForValue("<.*>");
	
	std::regex regForStart("<\\/");
	std::regex regForEnd("\\/>");
	std::smatch results;

	std::string temp;
	if (std::regex_search(content, results, regForName)) //name
	{
		temp = results[0].str().substr(1, results[0].str().length());
		temp = std::regex_replace(temp, std::regex("\\/"), "");
		name = temp;
	}

	if (std::regex_search(content, results, regForValue)) //value
	{
		temp = results[0].str().substr(1, results[0].str().length() - 2);
		temp = std::regex_replace(temp, std::regex("\\/"), "");
		value = temp;

	}

	if (std::regex_search(content, results, regForStart)) //StartEnd
	{
		isStart = false;
		isEnd = true;
	}

	else if (std::regex_search(content, results, regForEnd)) //StartEnd
	{
		isStart = true;
		isEnd = true;
	}
	else
	{
		isStart = true;
		isEnd = false;
	}
	//showLine();

}

void XMLTag::populateVector()
{
	std::string temp;
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (value[i] == ' ')
		{
			temp = value.substr(i+1, value.length());
			temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
			break;
		}
	}

	for (unsigned int i = 0; i < temp.length(); i++)
	{
			unsigned int j;
			std::string attributeName = "";
			std::string attributeValue = "";
			for (j = i; j < temp.length() && temp[j] != '=' ; j++)
			{
				attributeName = attributeName + temp[j];
			}
			for (j; j < temp.length(); j++)
			{
				if (temp[j] == '\"')
				{
					for (j = j+1; temp[j] != '\"'; j++)
					{
						attributeValue = attributeValue + temp[j];
					}
					i = j;
					break;
				}				
			}
			//attributeVector.push_back(Attribute(attributeName, attributeValue));
			attributeVector.emplace_back(attributeName, attributeValue);

	}
}

void XMLTag::SwitchIsEnd()
{
	isEnd = !isEnd;
}

void XMLTag::AddRemoveClosingSlash()
{
	if (isEnd)
	{

	}
}

void XMLTag::showLine() const
{
	std::cout << name << ", " << ((isStart) ? "tak" : "nie") << ", " << ((isEnd) ? "tak" : "nie") << ", " << value << std::endl;
	//std::cout << "<" << name << std::endl;
}

std::string XMLTag::getName() const
{
	return name;
}

std::string XMLTag::getValue() const
{
	return value;
}

std::vector<Attribute> XMLTag::getAttributeVector() const
{
	return attributeVector;
}

std::string XMLTag::getAllAttributeVectorXMLFormatted() const
{
	std::string returnal = "";
	for (auto attribute : attributeVector)
		returnal = returnal + attribute.getXMLFormatted() + " ";

	return returnal.substr(0, returnal.length()-1);
}

bool XMLTag::getIsStart() const
{
	return isStart;
}

bool XMLTag::getIsEnd() const
{
	return isEnd;
}

bool XMLTag::operator==(const XMLTag& right) const
{
	return (name == right.getName() && value == right.getValue() && attributeVector == right.getAttributeVector()
		&& isStart == right.getIsStart() && isEnd == right.getIsEnd());
}

