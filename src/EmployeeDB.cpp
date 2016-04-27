#include <iostream>
#include <string>
#include "../includes/AdminDB.h"
#include "../includes/Admin.h"
#include "../includes/EmployeeDB.h"
#include "../includes/Employee.h"

EmployeeDB::EmployeeDB(){ //Employee databas constructor

	//This method start a database of employeers with empty data

	int i=0;
	this->p = new Employee[20];

	for (i=0; i<10; i++){
			p[i].setLogin("");
			p[i].setPassword("");
		}		
}

int EmployeeDB::incluir (string c, string n, string f){ //Method to include employee on database
	
	if (existe (c) != -1){
		return 0;
	}
	
	int i = 0;
	//insert an employee
	for (i=0; i<10; i++){
		if (p[i].getLogin() == ""){
			p[i].setPassword(n);
			p[i].setLogin(c);
			p[i].setName(f);
			return 1;			
		}			
	}
}

int EmployeeDB::excluir (string c){ //method to delete employee from database
	int k = existe (c);
	
	//simple employee del, only set the login/pass/name to ""

	if (k != -1){
		p[k].setLogin("");	
		p[k].setPassword("");
		p[k].setName("");
		return 1;
	}
	return 0;			
}

void EmployeeDB::listar(){ //method to list employee from database
	int i=0;
	for (i=0; i<10; i++){
		if (p[i].getLogin() != ""){
			cout<<"---------------------"<<endl;
			p[i].print();
			cout<<"---------------------"<<endl;
		}
	}
}

Employee EmployeeDB::Authentication(Employee aux){ //method to authenticate employee login

	//this method scan the database, searching for a register match with the user inputs

	int i=0;
	Employee logado;
	for (i=0; i<10; i++){
		if (((p[i].getLogin()) == (aux.getLogin())) && ((p[i].getPassword()) == (aux.getPassword()))){
			logado.setLogin(p[i].getLogin());
			return logado;
		}
	}
	logado.setLogin("-1");
	return logado;
}


EmployeeDB::~EmployeeDB(){
	delete [] this->p;
}
