#include <iostream>
#include <cstdlib>

#ifndef Client_h
#define Client_h

#include "Pessoa.h"
using namespace std;

class Client : public Pessoa 
{
	private:
		string codClient;

	public:
		// constructor
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