#include <iostream>
#include <cstdlib>
#include "../includes/CarDB.h"
#define MAX 10

using namespace std;

CarDB::CarDB()
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

int CarDB::rent(string licensePlate, Client* client)
{
	int i;
	for(i=0; i<MAX;i++)
	{
		if(cars[i] != NULL)
		{
			if(cars[i]->getLicensePlate() == licensePlate)
			{
				if(cars[i]->availability())
				{
					cars[i]->rentCar(client);
					return 1;
				}
				else 
					return 2;
			}
		}
	}

	return 0;
}

int CarDB::release(string licensePlate)
{
	int i;
	for(i=0; i<MAX;i++)
	{
		if(cars[i]->getLicensePlate() == licensePlate  )
		{
			if(cars[i]->availability() == 0)
			{
				cars[i]->releaseCar();
				return 1;
			}
			else
			{
				cout<<"the car is not rented "<<endl;
				return 0;
			}

		}
	}

	return 0;
}

void CarDB::list()
{
	int i;
	for(i=0; i<MAX; i++)
	{
		if(cars[i]!= NULL )
		{
			cars[i]->printAll();
		}
	}
}

CarDB::~CarDB()
{
	
}