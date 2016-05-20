#include <iostream>
#include <string>
using namespace std;
#include "Pessoa.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Pessoa {
	private:
		 string login;
		 string password;
		 
	public:
		Employee();
		Employee(string , string, string, string, string);

		void setLogin(string); 
		void setPassword (string);

		string getLogin ();
		string getPassword();
		
		void print();
		~Employee();
};

#endif