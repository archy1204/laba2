#include "KeeperA.h"
#include<iostream>
#include <conio.h>
#include <windows.h>

KeeperA::KeeperA()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
	filter = " ";
}

KeeperA::KeeperA(int siz)
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
	filter = " ";
	Spawn(siz);
}

KeeperA::~KeeperA()
{
	clear();
	/*cout << "111" << endl;*/
}

KeeperA::KeeperA(const KeeperA& other)
{
	int cnt = 0;
	this->Size = other.Size;

	Aeroflot* current = nullptr;
	Aeroflot* current1 = nullptr;
	this->head = current;
	filter = " ";


	for (cnt = 0; cnt < this->Size; cnt++)
	{
		if (head == nullptr)
		{
			this->head = new Aeroflot(other.head->getdat());
			this->tail = this->head;
		}
		else
		{
			current = other.head;
			current1 = this->head;

			while (current1->pNext != nullptr)
			{
				current = current->pNext;
				current1 = current1->pNext;
			}
			current1->pNext = new Aeroflot(current->pNext->getdat(), current1->pNext, current1);
			this->tail = current1->pNext;
		}
	}
}

void KeeperA::swap(int fir, int sec)
{
	Aeroflot* first = this->head;
	Aeroflot* second = this->head;
	int cntf = 0;
	int cnts = 0;

	while (first != nullptr)
	{
		if (cntf == fir)
		{
			break;
		}
		first = first->pNext;
		cntf++;
	}
	while (second != nullptr)
	{
		if (cnts == sec)
		{
			break;
		}
		second = second->pNext;
		cnts++;
	}

	Aeroflot* temp = new Aeroflot("temp");

	temp->setdest(first->getdest());
	temp->setdat(first->getdat());
	temp->settype(first->gettype());

	first->setdest(second->getdest());
	first->setdat(second->getdat());
	first->settype(second->gettype());

	second->setdest(temp->getdest());
	second->setdat(temp->getdat());
	second->settype(temp->gettype());
	
	delete temp;
}

void KeeperA::sort()
{
	int i, j;
	string first;
	string second;
	Aeroflot* fir = this->head;
	Aeroflot* sec = fir->pNext;
	for (i = 0; i < Size - 1; i++)
	{

		// Last i elements are already 
		// in place 
		fir = this->head;
		sec = fir->pNext;
		for (j = 0; j < Size - i - 1; j++)
		{
			first = fir->getdest();
			second = sec->getdest();

			if ((first > second))
				this->swap(j, j + 1);
			fir = fir->pNext;
			sec = fir->pNext;
		}
	}
}

void KeeperA::pop_front()
{
	int si = this->Size;
	if (si)//Фикс исключения 1
	{
		Aeroflot* temp = head;
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

void KeeperA::pop_back()
{
	int si = this->Size;
	if (si)//Фикс исключения 2
	{
		Aeroflot* temp = tail;
		tail = tail->pPrev;//Исключение 2: попытка чтения поля пустого элемента
		if (si > 1)
		{
			tail->pNext = nullptr;
			delete temp;
			Size--;
		}
		else
		{
			this->head = nullptr;
			this->Size = 0;
		}
	}
	else
	{
		cout << "Bad Input: cannot delete an element of an empty container" << endl;
		Sleep(1000);
	}
}

void KeeperA::pop(int d)
{
	int si = this->Size;
	int i = 0;
	//if (si)

	if (d<0 || d>si - 1)
	{
		cout << "Incorrect range!" << endl;
		Sleep(1000);
	}
	else if (d == 0)
		this->pop_front();
	else if (d == si - 1)
		this->pop_back();
	else
	{
		Aeroflot* temp = this->head;
		Aeroflot* tem1 = nullptr;
		while (i != d)
		{
			tem1 = temp;
			temp = temp->pNext;
			temp->pPrev = tem1;
			i++;
		}
		temp->pPrev->pNext = temp->pNext;
		temp->pNext->pPrev = temp->pPrev;
		delete temp;
		Size--;
	}

}

void KeeperA::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Aeroflot(data);
		tail = this->head;
	}
	else
	{
		Aeroflot* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Aeroflot(data, current->pNext, current);
		tail = current->pNext;
	}
	Size++;
}

//void KeeperA::push_front(int data)
//{
//	if (head == nullptr)
//	{
//		head = new Aeroflot(data);
//		tail = this->head;
//	}
//	else
//	{
//		Aeroflot* current = this->head;
//
//		current->pPrev = new Aeroflot(data, current, current->pPrev);
//		head = current->pPrev;
//	}
//	Size++;
//}
//
//void KeeperA::push(int i, int d)
//{
//	int si = this->Size;
//	int cnt = 0;
//	if (i<0 || i> si)
//	{
//		cout << "Incorrect range!" << endl;
//		Sleep(1000);
//	}
//	else if (i == 0)
//		this->push_front(d);
//	else if (i == si)
//		this->push_back(d);
//	else
//	{
//
//		Aeroflot* current = this->head;
//		while (cnt != i - 1)
//		{
//			current = current->pNext;
//			cnt++;
//		}
//		Aeroflot* current1 = current->pNext;
//		current->pNext = new Aeroflot(d, current->pNext, current);
//		Size++;
//	}
//
//}

void KeeperA::clear()
{
	while (Size)
	{
		pop_front();
	}
}

void KeeperA::setfilt(string filter)
{
	this->filter = filter;
}


int KeeperA::GetSize()
{
	return Size;
}

int KeeperA::request_strt()
{
	int strt;
	cout << "Input container length: ";
	cin >> strt;
	return strt;
}

void KeeperA::Spawn()
{
	int strt = request_strt();
	for (int i = 0; i < strt; i++)
	{
		push_back(rand() % 100);
	}
}

void KeeperA::Spawn(int siz)
{
	int strt = siz;
	for (int i = 0; i < strt; i++)
	{
		push_back(rand() % 100);
	}
}

string KeeperA::operator[](const int index)
{
	int counter = 0;
	string ret;
	Aeroflot* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			ret = current->getdest();
			return ret;
		}
		current = current->pNext;
		counter++;
	}

}

void KeeperA::Show()
{
	if (filter == " ")
		cout << "Currently showing all flights" << endl << endl;
	else
		cout << "Currently showing flights serviced by the following plane type: "<< filter << endl << endl;
	Aeroflot* current = this->head;
	string cur_typ;
	this->sort();
	if (current != nullptr)
	{
		while (current->pNext != nullptr)
		{
			cur_typ = current->gettype();
			if (filter != " " && cur_typ == filter)
				cout<<*current;
			else if (filter == " ")
				cout << *current;
			
			current = current->pNext;
		}
		cur_typ = current->gettype();
		if (filter != " " && cur_typ == filter)
			cout << *current;
		else if (filter == " ")
			cout << *current;
	}
	else
		cout << "The list is empty!!!" << endl;
}

