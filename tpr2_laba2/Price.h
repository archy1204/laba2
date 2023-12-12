#pragma once

#include <iostream>
#include <string>
using namespace std;

class Price
{
public:
	Price* pNext;
	Price* pPrev;
	Price(int price = int(), Price* pNext = nullptr, Price* pPrev = nullptr);
	Price(string temp);

	void setName(string name="Unnamed product");
	void setPrice(int price = 0);
	void setShopName(string shopName="Unnamed shop");

	string getName();
	int getPrice();
	string getShopName();

	void display();


	friend std::istream& operator>>(std::istream& input, Price& product);
	friend std::ostream& operator<<(std::ostream& output, const Price& aero);

private:
	string name;
	int price;
	string shopName;
};