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

Senten::Senten(string text, Senten* pNext, Senten* pPrev)
{
	this->text = text;
	this->pNext = pNext;
	this->pPrev = pPrev;
}
