#include <iostream>
#include <string>
using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Admin {
	private:
		 string login;
		 string password;
	public:
		Admin();
		Admin(string, string);
		void setLogin(string); 
		void setPassword (string);
		string getLogin ();
		string getPassword();
		void print();
};

#endif