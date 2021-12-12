#include <iostream>
#include <fstream>
#include <string>
#include "Contact.h"

using namespace std;

void Contact::openFile(){
	contacts.open("contacts.txt");
	
	if(contacts.fail()){
		contacts.close();
		exit(1);
	}
}

void Contact::closeFile(){
	contacts.close();
}

void Contact::editContact(){
	cout<<"Enter first name: "; cin>>firstName;
	cout<<"Enter last name: "; cin>>lastName;
	cout<<"Enter phone number: "; cin>>number;
	contacts<<"First name: "<<firstName<<endl;
	contacts<<"Last name: "<<lastName<<endl;
	contacts<<"Phone number: "<<number<<endl;
	cout<<"Contact was added succesfully"<<endl;
}

void Contact::delContact(){
	ofstream file("contacts.txt");
	cout<<"Contact was deleted succesfully"<<endl;
}		

void Contact::displayContact(){	
	while(!contacts.eof()){
		getline(contacts,line);
		cout<<line<<endl;
	}
}

void Contact::mainMenu(){
	openFile();
	
	cout<<"	Main Menu"<<endl;
	cout<<"[1] Add or edit contact"<<endl;
	cout<<"[2] Display contact"<<endl;
	cout<<"[3] Delete contact"<<endl;
	cout<<"Pick a number [1-3] only please: "; 
	cin>>choice;
	
	switch(choice){
		case 1:
			editContact();
			break;
		case 2:
			displayContact();
			break;
		case 3:
			delContact();
			break;
	}
	
	cout<<"<3 THANK YOU <3"<<endl;
	closeFile();
}

int main(){
	Contact start;
	start.mainMenu();
	return 0;
}