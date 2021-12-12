#include <string>
#include <fstream>
#ifndef _CONTACT_H
#define _CONTACT_H

using namespace std;

class Contact{
public:
	void openFile();
	void closeFile();
	void editContact();
	void displayContact();
	void delContact();
	void mainMenu();
	
private:
	int choice;
	string firstName, lastName, number, line, nEmpty="n";
	fstream contacts;	
};

#endif