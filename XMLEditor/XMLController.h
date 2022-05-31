#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

class XMLController
{
private:
	string path;
	fstream file;

public:
	XMLController(string path);

	bool isXML();
	string getPath();
	static bool isXML(string path);
	void closeFile();
	string readFile();




};

