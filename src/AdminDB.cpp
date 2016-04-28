#include <iostream>
#include <string>
#include "../includes/AdminDB.h"
#include "../includes/Admin.h"
#include "../includes/Pessoa.h"


AdminDB::AdminDB(){ //Admin database constructor

	//This method start a database of employeers with empty data

	int i=0;
	this->p = new Admin[10];

	for (i=0; i<10; i++){
		if (i==0) {
			p[i].setLogin("admin");
			p[i].setPassword("123");
			p[i].setName("admin");
			p[i].setCpf("");
			p[i].setRG("");

		} else {
		p[i].setLogin("");
		p[i].setPassword("");
		p[i].setName("");
		p[i].setCpf("");
		p[i].setRG("");
		}
}		
}

int AdminDB::incluir (string _login, string _pass,string _name, string _CPF, string _RG){ //method to include admin account in db
	
	if (existe (_login) != -1){
		return 0;
	}
	
	int i = 0;
	
	for (i=0; i<10; i++){
		if (p[i].getLogin() == ""){
		p[i].setPassword(_pass);
		p[i].setLogin(_login);
		p[i].setName(_name);
		p[i].setCpf(_CPF);
		p[i].setRG(_RG);

		return 1;			
		}			
	}
}

int AdminDB::excluir (string c){ //method to delete admin account from db

	//simple admin del, only set the login/pass to ""

	int k = existe (c);
	
	if (k != -1){
		p[k].setLogin("");	
		p[k].setPassword("");
		p[k].setName("");
		p[k].setCpf("");
		p[k].setRG("");

		return 1;
	}
	return 0;			
}

void AdminDB::listar(){
	int i=0;
	for (i=0; i<10; i++){
		if (p[i].getLogin() != ""){
				cout<<"---------------------"<<endl;
				p[i].print();
				cout<<"---------------------"<<endl;
		}
	}
}

Admin AdminDB::Authentication(Admin aux){ //method to authenticate de admin login

	//this method scan the database, searching for a register match with the user inputs

	int i=0;
	Admin logado;
	for (i=0; i<10; i++){
		if (((p[i].getLogin()) == (aux.getLogin())) && ((p[i].getPassword()) == (aux.getPassword()))){
			logado.setLogin(p[i].getLogin());
			return logado;
		}
	}
	logado.setLogin("-1");
	return logado;
}


AdminDB::~AdminDB(){
	delete [] this->p;
}
