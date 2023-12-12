#pragma once

#include "Aeroflot.h"
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
	void push_back(int data = rand() % 1000);
	//void push_front(int data = rand() % 1000);
	//void push(int i = 0, int d = rand() % 1000);
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
	Aeroflot* head;
	Aeroflot* tail;
};
