#include <iostream>
#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
	private:
		 string login;
		 string password;
		 string name;
		 
	public:
		Employee();
		Employee(string, string, string);

		void setLogin(string); 
		void setPassword (string);
		void setName(string);

		string getLogin ();
		string getPassword();
		string getName();
		
		void print();
};

#endif