#include <iostream>
#include <cstdlib>

#ifndef motocycle_h
#define motocycle_h
#include "Client.h"
#include "Vehicle.h"

using namespace std;

class Motocycle : public Vehicle
{
	private:
		string motocycle;
		Client* rentedMotocycle;

	public:
		Motocycle(string, string,  string, int);

		//Functions SET
		void setMotocycle(string);
		void setRentedMotocycle(Client*);

		//functions GET
		string getMotocycle();
		Client* getRentedMotocycle();

		//others functions
		void rentMotocycle(Client*); // set cpf of Client
		void releaseMotocycle(); // release Motocycle
		void printAll();
		int availability();

		~Motocycle();
	
};


#endif