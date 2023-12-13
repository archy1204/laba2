#include "Price.h"

//#include <iostream>
//#include <fstream>

Price::Price(int price, Price* pNext, Price* pPrev)
{
	cout << "\nPrice constructor with parametrs";
	this->price = price;
	this->pNext = pNext;
	this->pPrev = pPrev;
	cin >> *this;
}

Price::Price(string temp)
{
	cout << "\nPrice constructor with parametrs";
	this->price = price;         
	this->pNext = pNext;
	this->pPrev = pPrev;
	setName();
	setShopName();
}

Price::Price(Price& pr)
{
	cout << "\nPrice copy constructor";
	this->price = pr.price;         
	this->pNext = pr.pNext;
	this->pPrev = pr.pPrev;
}

Price::Price()
{
	cout << "\nPrice constructor";
}
void Price::setName(string name)
{
	this->name = name;
}

void Price::setPrice(int price)
{
	this->price = price;
}

void Price::setShopName(string shopName)
{
	this->shopName = shopName;
}

string Price::getName()
{
	return this->name;
}

int Price::getPrice()
{
	return this->price;
}

string Price::getShopName()
{
	return this->shopName;
}

void Price::display()
{
	cout << name << endl << price << endl << shopName << endl << endl;
}

istream& operator>>(std::istream& input, Price& product)
{
	cin.ignore(32767, '\n');

	cout << "\nName of the product: ";
	getline(input, product.name);
	

	/*cout << "\nPrice of the product: ";
	input >> product.price;*/

	cout << "\Name of the shop of the product: ";
	getline(input, product.shopName);

	return input;
}

ostream& operator<<(ostream& output, const Price& aero)
{
	output << "Name: " << aero.name << endl<<"Price: "<<aero.price << endl <<"Shop: "<< aero.shopName << endl << endl;
	return output;
}
