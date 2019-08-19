#include<iostream>
#include<string>
#include <fstream>
#include "FileParser.h"
#include "XMLFileParser.h"
#include "JSONFileParser.h"
using namespace std;
int main()
{
	string Type;
	string FileName;
	cout << "Please enter the full file path :" << endl;
	cin >> FileName;
	ifstream in(FileName);
	if (FileName.find("xml") != string::npos)
	{
		Type = "XML";
		XMLFileParser xml_file(Type, FileName);
		xml_file.ParseFile();
	}
	else if (FileName.find("json") != string::npos)
	{
		Type = "JSON";
		JSONFileParser json_file(Type, FileName);
		json_file.ParseFile();
	}
	system("pause");
	return 0;
}