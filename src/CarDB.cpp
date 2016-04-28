#include <iostream>
#include <cstdlib>
#include "../includes/CarDB.h"
#define MAX 10

using namespace std;

CarDb::CarDB()
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		cars[i] = NULL;
	}
}

int CarDB::newCar(string car, string color, string licensePlate, int year)
{
	int i;
	for(i=0; i<MAX; i++)
	{
		if(cars[i] == NULL )
		{
			cars[i] = new Car(car, color, licensePlate, year);
			return 1;
		}
	}
	return 0;
}

int CarDB::rent()
{
	int i;
	for(i=0; i<MAX;i++)
	{

	}
}