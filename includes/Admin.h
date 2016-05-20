#include <iostream>
#include <string>
using namespace std;
#include "Pessoa.h"
#ifndef ADMIN_H
#define ADMIN_H

class Admin : public Pessoa {
	private:
		 string login;
		 string password;
	public:
		Admin();
		Admin(string, string,string,string,string);
		void setLogin(string); 
		void setPassword (string);
		string getLogin ();
		string getPassword();
		void print();
		~Admin();
};

#endif