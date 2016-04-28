#include <iostream>
#include <cstdlib>
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
		void consult(string);

		~Client();
	
};