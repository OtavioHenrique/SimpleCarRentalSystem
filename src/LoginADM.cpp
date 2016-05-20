#include <iostream>
#include <string>
#include "../includes/AdminDB.h"
#include "../includes/Admin.h"
#include "../includes/Employee.h"
#include "../includes/EmployeeDB.h"
#include "../includes/Pessoa.h"
#include <cstdlib>

using namespace std;

void askAdmInsert(Admin logged, AdminDB *p){ //Method to create an admin account
	string Username;
	string Passowrd;
	string Name;
	string Cpf;
	string RG;

	cout<<"Enter with Username: ";
	cin>>Username;
			
	cout<<"Enter with Passowrd: ";
	cin>>Passowrd;

	cout<<"Enter with Name: ";
	cin>>Name;
			
	cout<<"Enter with CPF: "; 
	cin>>Cpf;

	cout<<"Enter with RG: ";
	cin>>RG;

			
	if (p->incluir(Username, Passowrd, Name, Cpf, RG ) == 1){
		cout<<"Account created"<<endl;
	}
	else {
		cout<<"Error"<<endl;
	}
}

void admDeleteEmplo(EmployeeDB *p){ //Method to delete employee account
	string Username;
	string Passowrd;

	cout<<"Enter with employee Username that you want to delete: ";
	cin>>Username;
			
	if (p->excluir(Username) == 1){
		cout<<"Emplyee register Deleted"<<endl;
	}
	else{
		cout<<"Error while deleting"<<endl;
	}
}

void askListEmplo(EmployeeDB *p) { //Method to list employee accounts
	p->listar();
}

void admCreateEmplo(EmployeeDB *p){ //Method to create an employee account
	string password, name, login, cpf, rg;
	cout << "Enter with the employee name: ";
	cin >> name;
	cout << "Enter with the employee CPF: ";
	cin >> cpf;
	cout << "Enter with the employee RG: ";
	cin >> rg;
	cout << "Enter with the employee login: ";
	cin >> login;
	cout << "Enter with the employee password: ";
	cin >> password;

	if (p->incluir(login, password, name, cpf, rg) == 1){
		cout<<"Account created"<<endl;
	}
	else {
		cout<<"Error"<<endl;
	}
}

void askAdmDel(Admin logged, AdminDB *p) { //method to delete adm account
	string Username;
	string Passowrd;

	cout<<"Enter with Username that you want to delete: ";
	cin>>Username;
			
	if (p->excluir(Username) == 1){
		cout<<"Register Deleted"<<endl;
	}
	else{
		cout<<"Error while deleting"<<endl;
	}
}

void askAdmList(Admin logged, AdminDB *p) { //method to list adm accounts
	p->listar();
}

void admMenu (Admin logged, AdminDB *p, EmployeeDB *b) { //ADMINISTRATOR MENU

	int option;
	int auxiliar;
	do
	{
		std::system("clear");
		//std::system("cls"); //windows
		cout <<endl;
		cout << "Welcome to admin pannel" <<endl;
		cout << "You're logged with " << logged.getLogin() << " admin account" <<endl;
		cout << "What do you want?" <<endl;
		cout<<endl;
		cout << "============Admin Accounts Options====================="<<endl;
		cout<<endl;
		cout << "1 - Create new admin account" <<endl;
		cout << "2 - Delete admin account" <<endl;
		cout << "3 - List admin accounts" <<endl;
		cout <<endl;
		cout << "============Employee Accounts Options====================="<<endl;
		cout <<endl;
		cout << "4 - List employeers accounts" <<endl;
		cout << "5 - Create a employee account" <<endl;
		cout << "6 - Delete a employee account" <<endl;
		cout << "0 - Return" <<endl;

		cin >> option;

		switch(option){
			case 0:
				break;

			case 1:
				std::system("clear");
				askAdmInsert(logged, p);
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 2:
				std::system("clear");
				askAdmDel(logged, p);
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 3:
				std::system("clear");
				askAdmList(logged, p);
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 4:
				std::system("clear");
				askListEmplo(b);
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 5:
				std::system("clear");
				admCreateEmplo(b);
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 6:
				std::system("clear");
				admDeleteEmplo(b);
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			default:
				cout << "Please enter with a valid option" <<endl;
				break;
		}
	}while(option != 0);
}

void admLoginAuthentication (Admin aux, AdminDB *p , EmployeeDB *b) { //Authenticate administrator login with user inputs

	#ifdef OS_WINDOWS
		std::system("cls"); //windows clean
	#else
		std::system("clear"); //linux
	#endif

	Admin autentication;
	autentication = p->Authentication(aux);

	if (autentication.getLogin() != "-1") {
		admMenu(autentication, p, b);
	} else {
		cout << "Wrong Username/Password" <<endl;
		cout<<"\nPress ENTER to continue..."<<endl;
		cin.ignore();
		cin.get(); 
	}	
}

void admLogin(AdminDB *p, EmployeeDB *b){ //Ask for admin login/password and call login authentication 

	#ifdef OS_WINDOWS
		std::system("cls"); //windows clean
	#else
		std::system("clear"); //linux
	#endif
	cout << "Please log in with your admin account: " <<endl;

	string admUser;
	string admPass;
	cout << "Login: ";
	cin >> admUser;
	cout << "Password: ";
	cin >> admPass; //Depois tentar implementar função para aparecer *
	Admin aux(admUser,admPass, "", "", "");
	admLoginAuthentication(aux, p, b);

}

