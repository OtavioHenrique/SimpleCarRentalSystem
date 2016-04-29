#include <iostream>
#include <cstdlib>
#include "Client.h"
#include "Vehicle.h"

using namespace std;

#ifndef Car_h
#define Car_h

class Car : public Vehicle
{
	private:
		string car;
		Client* rentedCar;

	public:
		Car(string, string,  string, int);

		//Functions SET
		void setCar(string);
		void setRentedCar(Client*);

		//functions GET
		string getCar();
		Client* getRentedCar();

		//others functions
		void rentCar(Client*); // set cpf of Client
		void releaseCar(); // release car
		void printAll();
		int availability();

		~Car();
	
};

#endif