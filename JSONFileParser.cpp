#include<iostream>
#include<string>
#include <fstream>
#include "FileParser.h"
#include "JSONFileParser.h"
using namespace std;


JSONFileParser::JSONFileParser(string Type , string FileName)
{
	JSONType = Type;
	JSONFileName = FileName;
}

void JSONFileParser::ParseFile()
{
	string line;
	string arr[10];
	ofstream myfile;
	ifstream in(JSONFileName);
	int j = 0;
	while (getline(in, line))
	{
		std::string tmp; // strip whitespaces from the beginning
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == '}')
			{
				break;
			}
			else
			{
				tmp += line[i];
			}
		}

		if (tmp.find("{") != string::npos) {
			int i = tmp.find("{");
			tmp.replace(i, 1, "");
		}

		if (tmp.find("}") != string::npos) {
			int i = tmp.find("}");
			tmp.replace(i, 1, "");
		}
		for (int a = 0; a < tmp.length(); a++)
		{
			if (tmp.find("\"") != string::npos) {
				int i = tmp.find("\"");
				/*tmp.replace(i, 0, '"', ' ');*/
				tmp.replace(i, 1, "");
			}

		}

		if (tmp.find(",") != string::npos) {
			int i = tmp.find(",");
			tmp.replace(i, 1, "");
		}

		arr[j] = tmp;
		j++;


	}


	myfile.open("PP.txt");
	for (int i = 0; i < 10; i++)
	{
		myfile << arr[i] << endl;

	}
	myfile.close();
}
//
//JSONFileParser::~JSONFileParser()
//{
//}
