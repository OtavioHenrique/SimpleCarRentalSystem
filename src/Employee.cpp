#include <iostream>
#include <string>
#include "../includes/EmployeeDB.h"
#include "../includes/Employee.h"
#include "../includes/ClientDB.h"
#include <cstdlib>

using namespace std;

Employee::Employee() { //Employee Empty Constructor
}

Employee::Employee(string _username, string _password , string _name) { //Employee Constructor
		setLogin(_username);
		setPassword(_password);
		setName(_name);
}

string Employee::getLogin() { //Get Employee login method
	return login;
}

string Employee::getPassword() { //get employee password method
	return password;
}

string Employee::getName() { //get employee name password
	return name;
}

void Employee::setLogin(string _login) { //set employee login
	login = _login;
}

void Employee::setPassword(string _password){ //set employee password
	password = _password;
}

void Employee::setName(string _name){ //set employee name
	name = _name;
}

void Employee::print() { //print employee method
	cout << "Login: " << getLogin() << endl;
	cout << "Password: " << getPassword() << endl;
	cout << "Name: " << getName() <<endl;
}

void emploMenu (Employee logged, EmployeeDB *p, ClientDB *c) { //EMPLOYEE MENU

	int option;
	string name, cpf, RG, code;
	do
	{
		#ifdef OS_WINDOWS
			std::system("cls"); //windows clean
		#else
			std::system("clear"); //linux
		#endif
		cout <<endl;
		cout << "Welcome to Employee pannel" <<endl;
		cout << "You're logged with " << logged.getLogin() << " employee account" <<endl;
		cout << "What do you want?" <<endl;
		cout<<endl;
		cout<<endl;
		cout << "1 - New client account" <<endl;
		cout << "2 - Delete client account" <<endl;
		cout << "3 - List of client accounts" <<endl;
		cout << "4 - New car rent" <<endl;
		cout << "5 - New car devolution" <<endl;
		cout << "6 - List of car leased" <<endl;
		cout << "7 - List of available cars" <<endl;
		cout << "8 - To register new car" <<endl;
		cout << "4 - New motocycle rent" <<endl;
		cout << "5 - New motocycle devolution" <<endl;
		cout << "6 - List of motocycle leased" <<endl;
		cout << "7 - List of available motocycles" <<endl;
		cout << "8 - To register new motocycle" <<endl;
		cout << "9 - Quit"<<endl;

		cin >> option;
		
		switch(option)
		{
			case 1:
			
			#ifdef OS_WINDOWS
				std::system("cls"); //windows clean
			#else
				std::system("clear"); //linux
			#endif
				cout<<"Client name: "<<endl;
				cin>>name;
				cout<<"Client cpf: " <<endl;
				cin>>cpf;
				cout<<"Client RG: "<<endl;
				cin>>RG;
				cout<<"Client code: "<<endl;
				cin>>code;

				if(c->include(name,cpf,RG,code))
					cout<<"Successfully added customer"<<endl;
				else
					cout<<"space for customers full"<<endl;

				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 2:
				cout<<"customer cpf you want to delete: "<<endl;
				cin>>cpf;

				if(c->exclude(cpf))
					cout<<"Client successfully excluded "<<endl;
				else
					cout<<"error deleting client"<<endl;

				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 9:
				break;

			default:
				cout << "Please enter with a valid option" <<endl;
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;
		}

	}while(option != 9);

	}




void emploLoginAuthentication (Employee aux, EmployeeDB *p, ClientDB *c) { //Method to authenticate employee login

	#ifdef OS_WINDOWS
		std::system("cls"); //windows clean
	#else
		std::system("clear"); //linux
	#endif

	Employee autentication;
	autentication = p->Authentication(aux);

	if (autentication.getLogin() != "-1") {
		emploMenu(autentication, p, c);
	} else {
		cout << "Wrong Username/Password" <<endl;
		cout<<"\nPress ENTER to continue..."<<endl;
		cin.ignore();
		cin.get(); 
	}	
}



void employeeLogin(EmployeeDB *p, ClientDB *c) { //Method to employee login 
	#ifdef OS_WINDOWS
		std::system("cls"); //windows clean
	#else
		std::system("clear"); //linux
	#endif

	cout << "Please log in with your employee account: " <<endl;

	string emploUser;
	string emploPass;
	cout << "Login: ";
	cin >> emploUser;
	cout << "Password: ";
	cin >> emploPass; //Depois tentar implementar função para aparecer *
	Employee aux(emploUser,emploPass, "");
	emploLoginAuthentication(aux, p, c);
}