#include <iostream>
#include <cstdlib>
#include "Vehicle.h"
#include "Client.h"

using namespace std;

#ifndef Car_h
#define Car_h

class Car : public Vehicle
{
	private:
		string car;
		Client* rent;

	public:
		Car(string, string,  string, int);

		//Functions SET
		void setCar(string);

		//functions GET
		string getCar();

		//others functions
		void rentCar(Client*);
		void releaseCar();
		void printAll();

		~Car();
	
};

#endif