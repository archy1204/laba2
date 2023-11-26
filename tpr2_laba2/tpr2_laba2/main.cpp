#pragma once
#include "Keeper.h"
#include <iostream>
#define cles 1

using namespace std;

void options();
void menu();
void cls();

Keeper* keeper = new Keeper();

int main(void) {
	menu();
	return 0;
}

void menu() {
	int choice = 0;
	int k = 0;
	string str;
	options();
	cin >> choice;
	cout << endl;
	Fish* fish;
	Bird* bird;
	Cat* cat;
	switch (choice) {
	case 1: {
		cout << "What object do you want to create?\n";
		cout << "Fish.\n";
		cout << "Bird.\n";
		cout << "Cat.\n";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1: {
			string breed, color, feedType;
			cout << "Enter the breed, the color and the type of feed.\n";
			cin >> breed >> color >> feedType;
			fish = new Fish(breed, color, feedType);
			keeper->add(fish);
			break;
		}
		case 2: {

			string breed, color, feed, habitat;
			cout << "Enter the breed, the color, feed and habitat\n";
			cin >> breed >> color >> feed >> habitat;
			bird = new Bird(breed, color, feed, habitat);
			keeper->add(bird);
			break;
		}
		case 3: {
			string breed, color, ownerName, nickname;
			cout << "Enter the breed, the color, ownerName and nickname\n";
			cin >> breed >> color >> ownerName >> nickname;
			cat = new Cat(breed, color, ownerName, nickname);
			keeper->add(cat);
			break;
		}
		default:
			cout << "Incorrect input";
		}
		break;
	}
	case 2: {
		cout << "What object do you want to create?\n";
		cout << "Fish.\n";
		cout << "Bird.\n";
		cout << "Cat.\n";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1: {
			string breed, color, feedType;
			cout << "Enter the breed, the color and the type of feed.\n";
			cin >> breed >> color >> feedType;
			fish = new Fish(breed, color, feedType);
			cout << "Enter the number in list\n";
			cin >> k;
			cout << endl;
			try {
				if (k > keeper->getSize() - 1)
					throw "Invalid input\n";
			}
			catch (const char* ex) {
				cout << ex << endl;
				break;
			}
			if (k == keeper->getSize())
				keeper->add(fish);
			else
				keeper->insert(fish, k);
			break;
		}
		case 2: {
			string breed, color, feed, habitat;
			cout << "Enter the breed, the color, feed and habitat\n";
			cin >> breed >> color >> feed >> habitat;
			bird = new Bird(breed, color, feed, habitat);
			cout << "Enter the number in list\n";
			cin >> k;
			cout << endl;
			try {
				if (k > keeper->getSize() - 1)
					throw "Invalid input\n";
			}
			catch (const char* ex) {
				cout << ex << endl;
				break;
			}
			if (k == keeper->getSize())
				keeper->add(bird);
			else
				keeper->insert(bird, k);
			break;
		}
		case 3: {
			string breed, color, ownerName, nickname;
			cout << "Enter the breed, the color, ownerName and nickname\n";
			cin >> breed >> color >> ownerName >> nickname;
			cat = new Cat(breed, color, ownerName, nickname);
			cout << "Enter the number in list\n";
			cin >> k;
			cout << endl;
			try {
				if (k > keeper->getSize() - 1)
					throw "Invalid input\n";
			}
			catch (const char* ex) {
				cout << ex << endl;
				break;
			}
			if (k == keeper->getSize())
				keeper->add(cat);
			else
				keeper->insert(cat, k);
			break;
		}
		default:
			cout << "Incorrect input";
		}
	}
		  break;
	case 3: {
		int number;
		cout << "What is the number of the object in the list?\n";
		cin >> number;
		cout << endl;
		try {
			if (number > keeper->getSize() - 1)
				throw "Invalid input\n";
		}
		catch (const char* ex) {
			cout << ex << endl;
			break;
		}
		Animal* animal = keeper->get(number);
		animal->show();
		cout << endl;
	}
		  break;
	case 4: {
		int number;
		cout << "What animal do you want to delete?\n";
		cin >> number;
		cout << endl;
		try {
			if (number > keeper->getSize() - 1)
				throw "Invalid input\n";
		}
		catch (const char* ex) {
			cout << ex << endl;
			break;
		}
		keeper->remove(number)->show();
	}
		  break;
	case 5: {
		cout << "What object do you want to change?\n";
		int number;
		cin >> number;
		cout << endl;
		try {
			if (number > keeper->getSize() - 1)
				throw "Invalid input\n";
		}
		catch (const char* ex) {
			cout << ex << endl;
			break;
		}
		Animal* animal = keeper->remove(number);
		animal->change();
		keeper->insert(animal, number);
	}
		  break;
	case 6:
		keeper->show();
		break;
	case 7: {
		cout << keeper->getSize();
	}
		  break;
	case 8:
		keeper->clear();
		break;
	case 9:
		try {
			keeper->importList();
		}
		catch (...) {
			cout << "Reading from file failed\n";
		}
		break;
	case 10:
		try {
			keeper->exportList();
		}
		catch (...) {
			cout << "Writing to file failed\n";
		}
		break;
	case 11:
		exit(0);
	default:
		cout << "Incorrect input\n";

	}
	menu();
}

void cls()
{
	if (cles)
		system("cls");
}

void options() {
	cout << "\nMenu\n";
	cout << "1) Add new object.\n";
	cout << "2) Insert new object.\n";
	cout << "3) Get object.\n";
	cout << "4) Remove object from list.\n";
	cout << "5) Change the object\n";
	cout << "6) Show the list\n";
	cout << "7) Size of the list.\n";
	cout << "8) Clear the list.\n";
	cout << "9) Import list from file.\n";
	cout << "10) Export list to file.\n";
	cout << "11) exit\n";
}
