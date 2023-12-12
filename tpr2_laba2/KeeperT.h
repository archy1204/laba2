#pragma once
#include <iostream>
#include <string>
#include "Senten.h"
using namespace std;


class KeeperT
{
public:
	KeeperT();
	explicit KeeperT(int siz);
	~KeeperT();
	void pop_front();
	void push_back(int data = rand() % 10);
	void clear();
	int GetSize();
	int request_strt();
	void Spawn();
	void Spawn(int siz);
	string operator[](const int index);
	void Show();
private:
	int Size;
	Senten* head;
	Senten* tail;
};
