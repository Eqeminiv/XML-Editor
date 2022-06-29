#include "XMLLine.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <stack>
#include <regex>



XMLLine::XMLLine(std::string content)
{
	divideLine(content);

}

XMLLine::~XMLLine()
{

}

void XMLLine::divideLine(std::string content)
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
		this->name = temp;
	}

	if (std::regex_search(content, results, regForValue)) //value
	{
		temp = results[0].str().substr(1, results[0].str().length() - 2);
		temp = std::regex_replace(temp, std::regex("\\/"), "");
		this->value = temp;

	}

	if (std::regex_search(content, results, regForStart)) //StartEnd
	{
		this->isStart = false;
		this->isEnd = true;
	}

	else if (std::regex_search(content, results, regForEnd)) //StartEnd
	{
		this->isStart = true;
		this->isEnd = true;
	}
	else
	{
		this->isStart = true;
		this->isEnd = false;
	}
	showLine();

}

void XMLLine::showLine()
{
	std::cout << name << ", " << ((isStart) ? "tak" : "nie") << ", " << ((isEnd) ? "tak" : "nie") << ", " << value << std::endl;
}

std::string XMLLine::getName()
{
	return name;
}

std::string XMLLine::getValue()
{
	return value;
}

bool XMLLine::getIsStart()
{
	return isStart;
}

bool XMLLine::getIsEnd()
{
	return isEnd;
}