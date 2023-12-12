#pragma once

#include "Price.h"
#include <iostream>
#include <string>
using namespace std;


class KeeperA
{
public:
	KeeperA();
	explicit KeeperA(int siz);
	~KeeperA();
	KeeperA(const KeeperA& other);
	void swap(int fir, int sec);
	void sort();
	void pop_front();
	void pop_back();
	void pop(int d);
	void push_back(int price = rand() % 1000);
	void clear();
	void setfilt(string filter = " ");
	int GetSize();
	int request_strt();
	void Spawn();
	void Spawn(int siz);
	string operator[](int index);
	void Show();
private:
	int Size;
	string filter;
	Price* head;
	Price* tail;
};
