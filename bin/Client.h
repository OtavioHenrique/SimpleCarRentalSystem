#include <iostream>
#include <cstdlib>
#include "Pessoa.h"

using namespace std;

#ifndef Client_h
#define Client_h

class Client : public Pessoa 
{
	private:
		string codClient;

	public:
		Client(string,string,string,string);

		//Functions Set
		void setCodClient(string);

		//functions Get
		string getCodClient();

		//others functions
		void print();

		~Client();
	
};

#endif