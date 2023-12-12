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

Senten::Senten(int data, Senten* pNext, Senten* pPrev)
{
	this->data = data;
	this->pNext = pNext;
	this->pPrev = pPrev;
	this->text = "b";
}
