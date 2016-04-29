#include <iostream>
#include <cstdlib>
#include "Motocycle.h"

#ifndef MotocycleDB_h
#define MotocycleDB_h

using namespace std;

class MotocycleDB
{
	private:
		Motocycle* motocycles[10];

	public:
		MotocycleDB();

		int newMotocycle(string, string, string, int);
		int deleteMotocycle(string);
		int rent(string, Client*); //licensePlate and Client
		int release(string); // licensePlate
		int releaseAll(Client*);
		void listAvailable();
		void listLeased();

		~MotocycleDB();
	
};

#endif