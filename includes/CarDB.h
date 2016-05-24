#include <iostream>
#include <cstdlib>
#include "Car.h"
#define MAX 10

#ifndef CarDB_h
#define CarDB_h

using namespace std;

class CarDB
{
	private:
		Car* cars[MAX];

	public:
		CarDB();

		int newCar(string, string, string, int);
		int deleteCar(string);
		int rent(string, Client*); //licensePlate and Client
		int release(string); // licensePlate
		int releaseAll(Client*);
		void listAvailable();
		void listLeased();

		~CarDB();
	
};

#endif