#include <iostream>
#include <cstdlib>
#include <string>
#include "bin/Admin.h"
#include "bin/AdminDB.h"
using namespace std;

void askAdmInsert(Admin logged, AdminDB *p);

void askAdmDel(Admin logged, AdminDB *p);

void askAdmList(Admin logged, AdminDB *p);

void admMenu (Admin logged, AdminDB *p);

void admLoginAuthentication (Admin aux, AdminDB *p);

void admLogin(AdminDB *p);




int main(int argc, char** argv) {
	
	int option;
	AdminDB p;

	do {

		cout << "Welcome to the Guhtyk Car Rental clerk panel" << endl;
		cout <<endl;
		cout << "1. To Login" << endl;
		cout << "2. Forgot Password" << endl;
		cout << "3. Exit" << endl;
		cout << "4. Login as admin of the system" << endl;
		cin >> option;

		switch(option){

			case 1:

				break;
			case 2:
				break;
			case 3:
				exit(0);
				break;
			case 4:
				admLogin(&p);
			default:
				cout << "Please enter with valid option" << endl;

		}

	} while(option);
}