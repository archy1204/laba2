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

KeeperT::KeeperT()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

KeeperT::KeeperT(int siz)
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
	Spawn(siz);
	int phase = 0;

	ifstream fin("1.txt");
	string str = "";
	char separator[] = { '.', '?', '!', '…', '\0' };
	char first_let[] = {'A', 'B','C','D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z' };
	char symbol;
	Senten* current = this->head;

	while (fin.get(symbol))
	{
		switch (phase)
		{
			case 0://Поиск заглавной
				if (anyof(first_let, symbol))
				{
					str += symbol;
					phase = 1;
				}
				break;
			case 1://Запись предложения
				str += symbol;
				if (anyof(separator, symbol))
				{
					if (current == nullptr)
					{
						phase = 99;
						break;
					}
					phase = 2;
				}
				break;
			case 2:
				str += symbol;
				if (symbol == 32)
				{
					current->settext(str);
					current = current->pNext;
					str = "";
					phase = 0;
				}
				break;
			case 99:
				return;
		}
		
	}
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
void KeeperT::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Senten(data);
		tail = this->head;
	}
	else
	{
		Senten* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Senten(data, current->pNext, current);
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

void KeeperT::Spawn()
{
	int strt = request_strt();
	for (int i = 0; i < strt; i++)
	{
		push_back(rand() % 10);
	}
}

void KeeperT::Spawn(int siz)
{
	int strt = siz;
	for (int i = 0; i < strt; i++)
	{
		push_back(rand() % 10);
	}
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
	cout << endl;
	if (current->gettext()!="b")
		cout <<current->gettext() << endl;//3
	current = current->pPrev;
	if (current->gettext() != "b")
		cout << current->gettext() << endl;//2
	current = current->pPrev;
	if (current->gettext() != "b")
		cout << current->gettext() << endl;//1
	else
		cout << "No sentences were found";
}
