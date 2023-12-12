#include "KeeperT.h"
#include<iostream>
#include <conio.h>
#include <windows.h>

class Anyof
{
public:
	bool operator()(char* arr, char symbol)
	{
		for (int i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == symbol) {
				return true;
			}
		}
		return false;
	}
	bool operator()(char symbol, char* arr)
	{
		return anyof(arr, symbol);
	}

	bool operator()(std::string arr, char symbol)
	{
		for (int i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == symbol) {
				return true;
			}
		}
		return false;
	}
	bool operator()(char symbol, std::string arr)
	{
		return anyof(arr, symbol);
	}
}anyof;

KeeperT::KeeperT(int siz)
{
	Size = siz;
	head = nullptr;
	tail = nullptr;
}

KeeperT::KeeperT() {
	Size = 0;
	head = nullptr;
	tail = nullptr;
	// Spawn(siz);
	int phase = 0;

	ifstream fin("1.txt");
	string str = "";
	char separator[] = { '.', '?', '!', '…', '\0' };
	char first_let[] = { 'A', 'B','C','D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z' };
	char symbol;
	char predSymbol = 'a';
	bool isFirst = true;
	bool newSent = true;
	Senten* pred;
	Senten* current = nullptr;


	while (fin.get(symbol)) {
		if (newSent && predSymbol == 32 && anyof(first_let, symbol)) {
			push_back(str);
			/*pred = current;
			current == new Senten(str, nullptr, pred);
			if (pred != nullptr)
				pred->pNext = current;*/
			str = "";
			/*if (isFirst) {
				this->head = current;
				isFirst = false;
			}*/
			newSent = false;
		}

		if (anyof(separator, symbol))
			newSent = true;

		str += symbol;
		predSymbol = symbol;

	}
	push_back(str);
}

KeeperT::~KeeperT()
{
	clear();
	/*cout << "111" << endl;*/
}


void KeeperT::pop_front()
{
	int si = this->Size;
	if (si)//Фикс исключения 1
	{
		Senten* temp = head;
		head = head->pNext;//Исключение 1: попытка чтения поля пустого элемента
		delete temp;
		Size--;
	}
	else
	{
		cout << "Bad Input: cannot delete an element of an empty container" << endl;
		Sleep(1000);
	}
}

void KeeperT::push_back(string text)
{
	if (head == nullptr)
	{
		head = new Senten(text);
		tail = this->head;
	}
	else
	{
		Senten* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Senten(text, current->pNext, current);
		tail = current->pNext;
	}
	Size++;
}

void KeeperT::clear()
{
	while (Size)
	{
		pop_front();
	}
}


int KeeperT::GetSize()
{
	return Size;
}

int KeeperT::request_strt()
{
	int strt;
	cout << "Input container length: ";
	cin >> strt;
	return strt;
}

string KeeperT::operator[](const int index)
{
	int counter = 0;
	string ret;
	Senten* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			ret = current->gettext();
			return ret;
		}
		current = current->pNext;
		counter++;
	}

}
void KeeperT::Show()
{
	Senten* current = this->tail;
	if (current->gettext() == "") {
		cout << "\nNo sentences were found";
		return;
	}

	while (current != nullptr) {
		cout << current->gettext() << endl;
		current = current->pPrev;
	}
}