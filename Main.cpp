#include <iostream>
#include <cstdlib>
#include <string>
#include "bin/Admin.h"
#include "bin/AdminDB.h"
using namespace std;

void askAdmInsert(Admin logged, AdminDB *p){
	string Username;
	string Passowrd;

	cout<<"Enter with Username: ";
	cin>>Username;
			
	cout<<"Enter with Passowrd: ";
	cin>>Passowrd;
			
	if (p->incluir(Username, Passowrd ) == 1){
		cout<<"Account created"<<endl;
	}
	else {
		cout<<"Error"<<endl;
	}
}

void askAdmDel(Admin logged, AdminDB *p) {
	string Username;
	string Passowrd;

	cout<<"Enter with Username that you want to delete: ";
	cin>>Username;
			
	if (p->excluir(Username) == 1){
		cout<<"Register Deleted"<<endl;
	}
	else{
		cout<<"Error while excluding"<<endl;
	}
}

void askAdmList(Admin logged, AdminDB *p) {
	p->listar();
}

void admMenu (Admin logged, AdminDB *p) {
	int option;
	std::system("clear"); //linux
	//std::system("cls"); //windows
	cout <<endl;
	cout << "Welcome to admin pannel" <<endl;
	cout << "You're logged with  " << logged.getLogin() << " admin account" <<endl;
	cout << "What do you want?" <<endl;
	cout<<endl;
	cout << "1 - Create new admin account" <<endl;
	cout << "2 - Delete admin account" <<endl;
	cout << "3 - List admin accounts" <<endl;
	cout << "4 - Return" <<endl;

	cin >> option;
	
	
	switch(option){
		case 1:
			askAdmInsert(logged, p);
			break;
		case 2:
			askAdmDel(logged, p);
			break;
		case 3:
			askAdmList(logged, p);
			break;
		case 4:
			break;
		default:
			cout << "Please enter with a valid option" <<endl;
	}

}

void admLoginAuthentication (Admin aux, AdminDB *p) {

		std::system("clear"); //linux
		//std::system("cls"); //windows

		Admin autentication;
		autentication = p->Authentication(aux);
		if (autentication.getLogin() != "-1") {
			admMenu(autentication, p);
		} else {
			cout << "Wrong Username/Password" <<endl;
		}
		
}

void admLogin(AdminDB *p){

	std::system("clear"); //linux
	//std::system("cls"); //windows

	cout << "Please log in with your admin account: " <<endl;

	string admUser;
	string admPass;
	cout << "Login: ";
	cin >> admUser;
	cout << "Password: ";
	cin >> admPass; //Depois tentar implementar função para aparecer *
	Admin aux(admUser,admPass);
	admLoginAuthentication(aux, p);

}




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