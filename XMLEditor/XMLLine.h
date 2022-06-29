#pragma once
#include <string>

class XMLLine
{
private:
	std::string name;
	std::string value;
	bool isStart, isEnd;
	void divideLine(std::string content);
	


public:
	XMLLine(std::string content);
	~XMLLine();
	void showLine();
	std::string getName();
	std::string getValue();
	bool getIsStart();
	bool getIsEnd();

	
};