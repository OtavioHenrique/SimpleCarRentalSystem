//This is a simple car rental system developed for Object Oriented Programming Homework
//FEI University - Brazil
//Developed with <3 by: 
//Otavio Henrique
//Gabriel Medeiros
//Leonardo Papst

//For first time, log with admin with username = admin, password = 123
//To compile on GNU/linux systems : g++ Main.cpp AdminDB.cpp Employee.cpp EmployeeDB.cpp LoginADM.cpp -o Main


#include <iostream>
#include <cstdlib>
#include <string>
#include "bin/Admin.h"
#include "bin/AdminDB.h"
#include "bin/EmployeeDB.h"
#include "bin/Employee.h"
using namespace std;

void askAdmInsert(Admin logged, AdminDB *p);
void askAdmDel(Admin logged, AdminDB *p);
void askAdmList(Admin logged, AdminDB *p);
void admMenu (Admin logged, AdminDB *p, AdminDB *b);
void admLoginAuthentication (Admin aux, AdminDB *p);
void admLogin(AdminDB *p, EmployeeDB *b);
void admCreateEmplo(EmployeeDB *p);
void employeeLogin (EmployeeDB *p);



int main(int argc, char** argv) { //Principal menu
	
	int option;
	AdminDB p;
	EmployeeDB b;

	do {
		std::system("clear");
		cout <<endl;
		cout << "Welcome to the Guhtyk Car Rental clerk panel" << endl;
		cout <<endl;
		cout <<endl;
		cout << "======================" <<endl;
		cout <<endl;
		cout <<endl;
		cout << "1. Login as employee of the system" << endl;
		cout << "2. Login as admin of the system" << endl;
		cout << "3. Exit" << endl;
		cin >> option;

		switch(option){

			case 1:
				employeeLogin(&b);
				break;
			case 2:
				admLogin(&p, &b);
				break;
			case 3:
				exit(0);
				break;

			default:
				cout << "Please enter with valid option" << endl;
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

		}

	} while(option != 3);
}