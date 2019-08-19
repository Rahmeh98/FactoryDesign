#include<iostream>
#include<string>
#include <fstream>
#include "FileParser.h"
#include "XMLFileParser.h"
using namespace std;




XMLFileParser::XMLFileParser(string Type ,string FileName)
{
	XMLType = Type;
	XMLFileName = FileName;

}
void XMLFileParser:: ParseFile()
{
	string line;
	std::string arr[10];
	ofstream myfile;
	/*myfile.open("SI.xml");
	myfile << "<note>" << endl << "   <to>John</to>" << endl << "   <from>Smith</from>" << endl << "   <heading>Reminder</heading>" << endl << "   <body>Don't forget me this weekend!</body>" << endl << "</note>" << endl;
	myfile.close();*/
	ifstream in(XMLFileName);
	//cout << "first" << endl;
	int j = 0;
	
	while (getline(in, line))
	{
		/*cout << "begin" << endl;*/
		string tmp;// strip whitespaces from the beginning
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == '<'&& line[i + 1] == '/')
			{
				break;
			}
			else
			{
				tmp += line[i];
			}
		}
		/*for (int i = 0; i < tmp.length(); i++)
		{
			cout << tmp[i] << endl;
		}*/

		if (tmp.find("<") != string::npos) {
			int i = tmp.find("<");
			tmp.replace(i, 1, "");
		}

		if (tmp.find(">") != string::npos) {
			int i = tmp.find(">");
			tmp.replace(i, 1, ":");
		}

		arr[j] = tmp;
		j++;

	}

	myfile.open("et.txt");
	for (int i = 0; i < 10; i++)
	{
		myfile << arr[i] << endl;

	}
	myfile.close();
	/*cout << "done" << endl;*/
}

//XMLFileParser::~XMLFileParser()
//{
//
//}
