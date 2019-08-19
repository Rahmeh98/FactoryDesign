#pragma once
#include<string>
#include<iostream>
#include <fstream>
#ifndef XMLFILEPARSER_H
#define XMLFILEPARSER_H
//#include "FileParser.h"

using namespace std;
class XMLFileParser :public FileParser
{
private:
	string XMLType;
	string XMLFileName;
	
public:
	XMLFileParser(string,string);
	void ParseFile();

	

	
};
#endif // !1XMLFileParser.H

