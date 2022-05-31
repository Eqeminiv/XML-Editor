#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include "XMLController.h"
#include <filesystem>

using namespace std;

int main()
{
	string path;
	
	//cout << filesystem::exists("D:/test.xml");

	while (!filesystem::exists(path) || !XMLController::isXML(path))
	{
		cout << "Path input: " << endl;
		cin >> path;
		//cout << filesystem::exists(path);
	}
	XMLController controller(path);
	cout << controller.readFile();
	//cout << controller.getPath();
	//cout << controller.isXML();
	controller.closeFile();
	
	return 0;
}