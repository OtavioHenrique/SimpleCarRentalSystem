#include <iostream>
#include <cstdlib>
#include "Car.h"

#ifndef CarDB_h
#define CarDB_h

using namespace std;

class CarDB
{
	private:
		Car* cars[10];

	public:
		CarDB();

		int newCar(string, string, string, int);
		int rent(string, Client*); //licensePlate and Client
		int release(string); // licensePlate
		void list();

		~CarDB();
	
};

#endif