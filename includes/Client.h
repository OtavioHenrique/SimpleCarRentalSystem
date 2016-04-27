#include <iostream>
#include <cstdlib>
#include "Pessoa.h"

using namespace std;

class Client : public Pessoa 
{
	private:
		string codClient;

	public:
		Client(string,string,string,string);

		//Functions Set
		void setCodClient();

		//functions Get
		string getCodClient();

		//others functions
		void print();

		~Client();
	
};