#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Senten
{
public:
	Senten* pNext;
	Senten* pPrev;

	void setdat(int data = 0);
	void settext(string text);

	string gettext();

	Senten(string text = "", Senten* pNext = nullptr, Senten* pPrev = nullptr);
private:
	int data;
	string text;
};
