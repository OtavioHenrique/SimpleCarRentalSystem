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
		int rent();
		int release();
		void list();

		~CarDB();
	
};

#endif