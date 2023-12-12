#pragma once

#include <iostream>
#include <string>
using namespace std;

class Aeroflot
{
public:
	Aeroflot* pNext;
	Aeroflot* pPrev;
	Aeroflot(int data = int(), Aeroflot* pNext = nullptr, Aeroflot* pPrev = nullptr);
	Aeroflot(string temp);

	void setdest(string dest="a - b");
	void setdat(int dat = 0);
	void settype(string typ="plane");

	string getdest();
	int getdat();
	string gettype();

	void display();


	friend std::istream& operator>>(std::istream& input, Aeroflot& aero);
	friend std::ostream& operator<<(std::ostream& output, const Aeroflot& aero);

private:
	string destin;
	int data;
	string type;
};