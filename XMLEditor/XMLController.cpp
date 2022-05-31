#include "XMLController.h"

using namespace std;

XMLController::XMLController(string path)
{
	this->path = path;
}

bool XMLController::isXML()
{
	string tempPath = path.substr(path.find_last_of(".") + 1);
	for (int i = 0; i < tempPath.length(); i++)
		tempPath[i] = toupper(tempPath[i]);
	if (tempPath == "XML")
		return true;
	return false;
}

bool XMLController::isXML(string path) //?
{
	string tempPath = path.substr(path.find_last_of(".") + 1);
	for (int i = 0; i < tempPath.length(); i++)
		tempPath[i] = toupper(tempPath[i]);
	if (tempPath == "XML")
		return true;
	return false;
}

void XMLController::closeFile()
{
	if (file.is_open())
		file.close();
	return;
}

string XMLController::readFile()
{
	file.open(path, ios::in); //should be done in other method?
	string temp;
	if (file.is_open())
	{
		getline(file, temp, '\0');
		return temp;
	}
	return "";
	
}
string XMLController::getPath()
{
	return path;
}





