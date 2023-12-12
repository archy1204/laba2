#include "KeeperA.h"
#include "KeeperT.h"

#include <list>
#include <iostream>
#define cles 1
using namespace std;

void menu();
void cls();
void men();
void disp();
void inc();
void imp();
void exp();


int main(void)
{
	/*string fir = "bbbbbbbbbbb";
	string sec = "baaaaaaaaaa";
	if (fir > sec)
		cout << fir;
	else
		cout << sec;*/
	menu();
	return 0;
}

void menu()
{
	int choice = 0;
	int k = 0;
	int d = 0;
	string filt;
	cls();
	KeeperA bob(0);
	KeeperA aero(bob);
	KeeperT texo(3);
	filt = " ";
	k = 0;
	men();
	//вывод в консоль
	while (choice != 3)
	{
		cin >> choice;
		cls();
		switch (choice)
		{
		case 1: //////////////////////////////Open aeroflot
		{
			aero.push_back();
			k = 0;
			cls();
			disp();
			aero.Show();
			while (k != 5)
			{
				cin >> k;
				switch (k)
				{
				case 1:////Add element
					cls();
					disp();
					aero.push_back();
					cls();
					disp();
					aero.Show();
					break;
				case 2://///Remove element
					cls();
					disp();
					cout << "What flight you'd like to remove?" << endl;
					cin >> d;
					aero.pop(d);
					cls();
					disp();
					aero.Show();
					break;

				case 3:///Show all flights
					cls();
					disp();
					aero.setfilt();
					aero.Show();
					break;
				case 4:///Show flights flown by this type of plane
					cls();
					disp();
					cout << "By what plane type would you like to filter the flights?" << endl;
					cin >> filt;
					aero.setfilt(filt);
					cls();
					disp();
					aero.Show();
					break;
				case 5:///To main menu
					cls();
					men();

					break;
				default:
					cls();
					disp();

					inc();
					break;
				}
			}
			break;
		}
		case 2: //////////////////////////////Output edited text from file
		{
			cls();
			men();
			texo.Show();
			break;
		}
		case 3://////////////////////////////Exit
		{
			cls();
			men();
			break;
		}
		default:
		{
			cls();
			men();

			inc();
			break;
		}
		}
	}
}

void men()
{
	cout << "Menu:\n(1)Aeroflot\n(2)Output text from file\n(3)Exit"<< endl;
}

void disp()
{
	cout << "(1)Add element\n(2)Remove element\n(3)Show all flights\n(4)Filter by plane type\n(5)To menu" << endl << endl;
}

void cls()
{
	if (cles)
		system("cls");
}

void elad()
{
	cout << "Element added!\n";
}

void elre()
{
	cout << "Element removed!\n";
}

void inc()
{
	cout << "Incorrect input!\n" << endl;
}
