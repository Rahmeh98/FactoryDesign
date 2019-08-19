#pragma once
#include<string>
#include<iostream>
#ifndef JSONFILEPARSER_H
#define JSONFILEPARSER_H

using namespace std;
class JSONFileParser : public FileParser
{
private:
	string JSONType;
	string JSONFileName;
public:
	JSONFileParser(string , string);
	void ParseFile();
	
};
#endif // !JSONFILEPARSER_H


