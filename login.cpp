#include <iostream>
#include <string>
//#include "bin/Employee.h"
#include "bin/AdminDB.h"
#include "bin/Admin.h"

using namespace std;

	Admin::Admin() {
	}

	Admin::Admin(string _username, string _password) {
			setLogin(_username);
			setPassword(_password);
	}

	string Admin::getLogin() {
		return login;
	}

	string Admin::getPassword() {
		return password;
	}

	void Admin::setLogin(string _login) {
		login = _login;
	}

	void Admin::setPassword(string _password){
		password = _password;
	}

	void Admin::print() {
		cout << "Login: " << getLogin() << endl;
		cout << "Password: " << getPassword() << endl;
	}

	AdminDB::AdminDB(){
		int i=0;
		this->p = new Admin[10];
		
		for (i=0; i<10; i++){
			if (i==0) {
				p[i].setLogin("admin");
				p[i].setPassword("123");	
			} else {
			p[i].setLogin("");
			p[i].setPassword("");
			}
		}		
	}

	int AdminDB::incluir (string c, string n){
			
			if (existe (c) != -1){
				return 0;
			}
			
			int i = 0;
			
			for (i=0; i<10; i++){
				if (p[i].getLogin() == ""){
				p[i].setPassword(n);
				p[i].setLogin(c);
				return 1;			
				}			
			}
		}
		
		int AdminDB::excluir (string c){
			int k = existe (c);
			
			if (k != -1){
				p[k].setLogin("");	
				p[k].setPassword("");
				return 1;
			}
			return 0;			
		}
		
		void AdminDB::listar(){
			int i=0;
			for (i=0; i<10; i++){
				if (p[i].getLogin() != ""){
					p[i].print();
				}
			}
		}

		Admin AdminDB::Authentication(Admin aux){
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
