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
	//todo
}

XMLTag::XMLTag(const XMLTag &xmlNode)
{
	name = xmlNode.name;
	value = xmlNode.value;
	attributeVector = xmlNode.attributeVector;
	isStart = xmlNode.isStart;
	isEnd = xmlNode.isEnd;
	
}

XMLTag::XMLTag(std::string content)
{
	divideLine(content);
	if (isStart)
	{
		populateVector();
	}

}

XMLTag::~XMLTag()
{

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
	showLine();

}

void XMLTag::populateVector()
{
	std::string temp;
	for (int i = 0; i < value.length(); i++)
	{
		if (value[i] == ' ')
		{
			temp = value.substr(i+1, value.length());
			temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
			//std::cout << temp;
			break;
		}
	}

	for (int i = 0; i < temp.length(); i++)
	{
			int j;
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
			attributeVector.push_back(Attribute(attributeName, attributeValue));
	}

	/*for (int i = 0; i < attributeVector.size(); i++)
	{
		std::cout << i+1 << "#: name:" << attributeVector[i].getName() << " - value:" << attributeVector[i].getValue() << std::endl;
	}*/

}

void XMLTag::showLine()
{
	std::cout << name << ", " << ((isStart) ? "tak" : "nie") << ", " << ((isEnd) ? "tak" : "nie") << ", " << value << std::endl;
}

std::string XMLTag::getName() const
{
	return name;
}

std::string XMLTag::getValue() const
{
	return value;
}

bool XMLTag::getIsStart() const
{
	return isStart;
}

bool XMLTag::getIsEnd() const
{
	return isEnd;
}

XMLTag XMLTag::operator=(const XMLTag& rightXml)
{
	name = rightXml.name;
	value = rightXml.value;
	attributeVector = rightXml.attributeVector;
	isStart = rightXml.isStart;
	isEnd = rightXml.isEnd;
	return *this;
}