#include "Senten.h"

void Senten::setdat(int data)
{
	this->data = data;
}

void Senten::settext(string text)
{
	this->text = text;
}

string Senten::gettext()
{
	return this->text;
}

Senten::Senten(Senten& sent)
{
	cout << "\nSenten copy constructor";
	this->text = sent.text;
	this->pNext = sent.pNext;
	this->pPrev = sent.pPrev;
}

Senten::Senten(string text, Senten* pNext, Senten* pPrev)
{
	cout << "\nSenten constructor with parametrs";
	this->text = text;
	this->pNext = pNext;
	this->pPrev = pPrev;
}

Senten::Senten()
{
	cout << "\nSenten constructor";
	this->text = "";
	this->pNext = nullptr;
	this->pPrev = nullptr;
}

Senten::~Senten()
{
	cout << "Senten destrucor";
}
