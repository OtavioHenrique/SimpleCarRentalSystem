#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef Pessoa_h
#define Pessoa_h

class Pessoa
{
	private:
		string name;
		string cpf;
		string RG;

	public:
		//constructor
		Pessoa();
		Pessoa(string,string,string);

		// Functions set
		void setName(string);
		void setCpf(string);
		void setRG(string);

		// Functions get
		string getName();
		string getCpf();
		string getRG();

		//others functions

		void print();	

		//destructor
		~Pessoa();
	
};

#endif