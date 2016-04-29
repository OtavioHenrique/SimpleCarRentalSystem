#include <iostream>
#include <string>
#include "../includes/EmployeeDB.h"
#include "../includes/Employee.h"
#include "../includes/Pessoa.h"
#include "../includes/ClientDB.h"
#include "../includes/CarDB.h"
#include "../includes/MotocycleDB.h"
#include <cstdlib>

#ifdef _WIN32
	#define SISTEMA "cls"

#else
	#define SISTEMA "clear"

#endif

using namespace std;

Employee::Employee() { //Employee Empty Constructor
}

Employee::Employee(string _username, string _password , string _name, string _CPF, string _RG) { //Employee Constructor
		setLogin(_username);
		setPassword(_password);
		setName(_name);
		setCpf(_CPF);
		setRG(_RG);
}

string Employee::getLogin() { //Get Employee login method
	return login;
}

string Employee::getPassword() { //get employee password method
	return password;
}


void Employee::setLogin(string _login) { //set employee login
	login = _login;
}

void Employee::setPassword(string _password){ //set employee password
	password = _password;
}

void Employee::print() { //print employee method
	cout << "Login: " << getLogin() << endl;
	cout << "Password: " << getPassword() << endl;
	cout << "Name: " << getName() <<endl;
	cout << "CPF: " << getCpf() << endl;
	cout << "RG: " << getRG() << endl;
}




void emploMenu (Employee logged, EmployeeDB *p, ClientDB *c, CarDB* car, MotocycleDB *motocycle) { //EMPLOYEE MENU

	int option;
	string name, cpf, RG, code;
	string nameOfCar, nameOfmotocycle,color, licensePlate; 
	int year,aux;
	Client *client;
	do
	{
		std::system(SISTEMA);


		cout <<endl;
		cout << "Welcome to Employee pannel" <<endl;
		cout << "You're logged with " << logged.getLogin() << " employee account" <<endl;
		cout << "What do you want?" <<endl;
		cout<<endl;
		cout<<endl;


		cout<<"========== Clients =========="<<endl;
		cout << "1 - New client account" <<endl;
		cout << "2 - Delete client account" <<endl;
		cout << "3 - List of client accounts" <<endl;

		cout<<"========== Cars =========="<<endl;

		cout << "4 - New car rent" <<endl;
		cout << "5 - New car devolution" <<endl;
		cout << "6 - List of car leased" <<endl;
		cout << "7 - List of available cars" <<endl;
		cout << "8 - To register new car" <<endl;



		cout<<"========== Motocycles =========="<<endl;

		cout << "9 - New motocycle rent" <<endl;
		cout << "10 - New motocycle devolution" <<endl;
		cout << "11 - List of motocycle leased" <<endl;
		cout << "12 - List of available motocycles" <<endl;
		cout << "13 - To register new motocycle" <<endl;
		cout << "14 - To delete a motocycle " <<endl<<endl;

		cout << "0 - Quit"<<endl;


		cin >> option;
		
		switch(option)
		{

			case 0:
				break;
			case 1:
			
				std::system(SISTEMA);

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
				std::system(SISTEMA);
				cout<<"customer cpf you want to delete: "<<endl;
				cin>>cpf;

				client = c->find(cpf);

				if(client != NULL)
				{
					car->releaseAll(client);
					motocycle->releaseAll(client);
					c->exclude(cpf);
					cout<<"Client successfully excluded "<<endl;
				}
				else
					cout<<"Customer does not exist"<<endl;


				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 3:
				std::system(SISTEMA);

				c->list();
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 4:
				std::system(SISTEMA);
				cout<<"Car license plate: "<<endl;
				cin>>licensePlate;
				cout<<"Client cpf: "<<endl;
				cin>>cpf;
				client = c->find(cpf);

				if(client != NULL)
				{
					aux = car->rent(licensePlate, client );

					if( aux == 2  )
						cout<<"Unavailable car "<<endl;
					else if(aux == 0)
						cout<<"License plate not found"<<endl;
					else if(aux)
						cout<<"Rent successfully"<<endl;

				}
				else
					cout<<"Customer not found"<<endl;
				
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 5:
				std::system(SISTEMA);
				cout<<"Car license plate: "<<endl;
				cin>>licensePlate;
				aux = car->release(licensePlate);
				if(aux == 1)
					cout<<"Successfully relsease car"<<endl;
				else if(aux == 0)
					cout<<"Car not found"<<endl;

				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 6:
				std::system(SISTEMA);
				car->listLeased();
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 7:
				std::system(SISTEMA);
				car->listAvailable();
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 8:
				std::system(SISTEMA);
				cout<<"Car name: "<<endl;
				cin>>nameOfCar;
				cout<<"Car color: "<<endl;
				cin>>color;
				cout<<"Car license plate: "<<endl;
				cin>>licensePlate;
				cout<<"Car year: "<<endl;
				cin>>year;

				if(car->newCar(nameOfCar, color, licensePlate, year) )
					cout<<"Successfully added car "<<endl;
				else
					cout<<"Bank full of cars"<<endl;

				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 9:
				std::system(SISTEMA);
				cout<<"Motocycle license plate: "<<endl;
				cin>>licensePlate;
				cout<<"Client cpf: "<<endl;
				cin>>cpf;
				client = c->find(cpf);

				if(client != NULL)
				{
					aux = motocycle->rent(licensePlate, client );

					if( aux == 2  )
						cout<<"Unavailable motocycle "<<endl;
					else if(aux == 0)
						cout<<"License plate not found"<<endl;
					else if(aux)
						cout<<"Rent successfully"<<endl;

				}
				else
					cout<<"Customer not found"<<endl;
				
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 10:
				std::system(SISTEMA);
				cout<<"Motocycle license plate: "<<endl;
				cin>>licensePlate;
				aux = motocycle->release(licensePlate);
				if(aux == 1)
					cout<<"Successfully relsease motocycle"<<endl;
				else if(aux == 0)
					cout<<"Motocycle not found"<<endl;

				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 11:
				std::system(SISTEMA);
				motocycle->listLeased();
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 12:
				std::system(SISTEMA);
				motocycle->listAvailable();
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 13:
				std::system(SISTEMA);
				cout<<"Motocycle name: "<<endl;
				cin>>nameOfmotocycle;
				cout<<"Motocycle color: "<<endl;
				cin>>color;
				cout<<"motocycle license plate: "<<endl;
				cin>>licensePlate;
				cout<<"Motocycle year: "<<endl;
				cin>>year;

				if(motocycle->newMotocycle(nameOfmotocycle, color, licensePlate, year) )
					cout<<"Successfully added motocycle "<<endl;
				else
					cout<<"Bank full of motocycles"<<endl;

				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;

			case 14:
				std::system(SISTEMA);
				cout<<"Motocycle license plate: "<<endl;
				cin>>licensePlate;

				if( motocycle->deleteMotocycle(licensePlate) )
					cout<<"Successfully deleted motocycle"<<endl;
				else
					cout<<"License plate not found"<<endl;

				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;


			default:
				std::system(SISTEMA);

				cout << "Please enter with a valid option" <<endl;
				cout<<"\nPress ENTER to continue..."<<endl;
				cin.ignore();
				cin.get(); 
				break;
		}




	}while(option);


	}


void emploLoginAuthentication (Employee aux, EmployeeDB *p, ClientDB *c, CarDB* car, MotocycleDB* motocycle) { //Method to authenticate employee login

	std::system(SISTEMA);

	Employee autentication;
	autentication = p->Authentication(aux);

	if (autentication.getLogin() != "-1") {
		emploMenu(autentication, p, c, car, motocycle);
	} else {
		cout << "Wrong Username/Password" <<endl;
		cout<<"\nPress ENTER to continue..."<<endl;
		cin.ignore();
		cin.get(); 
	}	
}



void employeeLogin(EmployeeDB *p, ClientDB *c, CarDB* car, MotocycleDB *motocycle) { //Method to employee login 

	std::system(SISTEMA);
	cout << "Please log in with your employee account: " <<endl;

	string emploUser;
	string emploPass;

	cout << "Login: ";
	cin >> emploUser;
	cout << "Password: ";
	cin >> emploPass; //Depois tentar implementar função para aparecer *

	Employee aux(emploUser,emploPass, "", "", "");



	emploLoginAuthentication(aux, p, c, car, motocycle);

}
