#include "Aeroflot.h"

//#include <iostream>
//#include <fstream>

Aeroflot::Aeroflot(int data, Aeroflot* pNext, Aeroflot* pPrev)
{
	this->data = data;
	this->pNext = pNext;
	this->pPrev = pPrev;
	setdest();
	settype();
	//Aeroflot* temp = this;
	cin >> *this;
}

Aeroflot::Aeroflot(string temp)
{
	this->data = data;
	this->pNext = pNext;
	this->pPrev = pPrev;
	setdest();
	settype();
}

void Aeroflot::setdest(string dest)
{
	this->destin = dest;
}

void Aeroflot::setdat(int dat)
{
	this->data = dat;
}

void Aeroflot::settype(string typ)
{
	this->type = typ;
}

string Aeroflot::getdest()
{
	return this->destin;
}

int Aeroflot::getdat()
{
	return this->data;
}

string Aeroflot::gettype()
{
	return this->type;
}

void Aeroflot::display()
{
	cout << destin << endl << data << endl << type << endl << endl;
}

istream& operator>>(std::istream& input, Aeroflot& aero)
{
	cin.ignore(32767, '\n');
	string depart;
	string destin;
	cout << "\nPlace of departure: ";
	getline(input, depart);
	cout << "\nDestination: ";
	getline(input, destin);
	aero.setdest(depart + " - " + destin);

	cout << "\nPlane type: ";
	getline(input, aero.type);

	/*cout << "\nNumber of the flight: ";
	input >> aero.data;*/

	//input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return input;
}

ostream& operator<<(ostream& output, const Aeroflot& aero)
{
	output << "Destination: " << aero.destin << endl<<"Flight number: "<<aero.data << endl <<"Plane type: "<< aero.type << endl << endl;
	return output;
}
