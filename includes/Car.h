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
		string rentedCar;

	public:
		Car(string, string,  string, int);

		//Functions SET
		void setCar(string);

		//functions GET
		string getCar();

		//others functions
		void rentCar(string);
		void releaseCar();
		void printAll();
		int availability();

		~Car();
	
};

#endif