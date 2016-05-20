#include <iostream>
#include <string>
using namespace std;
#include "../includes/Admin.h"

Admin::Admin() { //admin empty constructor
}

Admin::Admin(string _username, string _password, string _name, string _cpf, string _rg) {//admin constructor
		setLogin(_username);
		setPassword(_password);
		setName(_name);
		setCpf(_cpf);
		setRG(_rg);
}

string Admin::getLogin() { //function to return login
	return login;
}

string Admin::getPassword() { //function to return password
	return password;
}

void Admin::setLogin(string _login) { //function to set login
	login = _login;
}

void Admin::setPassword(string _password){ //function to set password
	password = _password;
}

void Admin::print() { //Process to print admin account
	cout << "Login: " << getLogin() << endl;
	cout << "Password: " << getPassword() << endl;
	cout << "Name: " << getName() << endl;
	cout << "CPF: " << getCpf() << endl;
	cout << "RG: " << getRG() << endl;
}

Admin::~Admin()
{

}