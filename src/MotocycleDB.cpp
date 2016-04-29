#include <iostream>
#include <cstdlib>
#include "../includes/MotocycleDB.h"
#define MAX 10

using namespace std;

MotocycleDB::MotocycleDB()
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		motocycles[i] = NULL;
	}
}

int MotocycleDB::newMotocycle(string motocycle, string color, string licensePlate, int year)
{
	int i;
	for(i=0; i<MAX; i++)
	{
		if(motocycles[i] == NULL )
		{
			motocycles[i] = new Motocycle(motocycle, color, licensePlate, year);
			return 1;
		}
	}
	return 0;
}

int MotocycleDB::deleteMotocycle(string licensePlate)
{
	int i;
	for (int i = 0; i < MAX; i++)
	{
		if(motocycles[i] != NULL)
		{
			if(motocycles[i]->getLicensePlate() == licensePlate )
			{
				delete(motocycles[i]);
				motocycles[i] = NULL;
				return 1;
			}
		}
	}

	return 0;
}

int MotocycleDB::rent(string licensePlate, Client* client)
{
	int i;
	for(i=0; i<MAX;i++)
	{
		if(motocycles[i] != NULL)
		{
			if(motocycles[i]->getLicensePlate() == licensePlate)
			{
				if(motocycles[i]->availability())
				{
					motocycles[i]->rentMotocycle(client);
					return 1;
				}
				else 
					return 2;
			}
		}
	}

	return 0;
}

int MotocycleDB::release(string licensePlate)
{
	int i;
	for(i=0; i<MAX;i++)
	{
		if(motocycles[i] != NULL)
		{
			if(motocycles[i]->getLicensePlate() == licensePlate  )
			{
				if(motocycles[i]->availability() == 0)
				{
					motocycles[i]->releaseMotocycle();
					return 1;
				}
				else
				{
					cout<<"the motocycle is not rented "<<endl;
					return 2;
				}

			}
		}
	}

	return 0;
}

int MotocycleDB::releaseAll(Client* client)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		if(motocycles[i] != NULL )
		{
			if(motocycles[i]->getRentedMotocycle() == client )
			{
				if(motocycles[i]->availability() == 0)
				{
					motocycles[i]->releaseMotocycle();
				}
			}
		}
	}
}

void MotocycleDB::listAvailable()
{
	int i, cont = 0;
	for(i=0; i<MAX; i++)
	{
		if(motocycles[i] != NULL)
		{
			if(motocycles[i]-> availability() )
			{
				motocycles[i]->printAll();
			}
			else
				cont++;
		}
		else cont++;
	}

	if(cont == MAX)
		cout<<"No available motocycles "<<endl;
}

void MotocycleDB::listLeased()
{
	int i,cont = 0;
	for(i=0; i<MAX; i++)
	{
		if(motocycles[i] != NULL)
		{
			if(motocycles[i]->availability() == 0)
			{
				motocycles[i]->printAll();
			}
			else 
				cont++;
		}
		else cont++;
	}

	if(cont == MAX)
		cout<<"Without rented motocycles "<<endl;	
}

MotocycleDB::~MotocycleDB()
{
	
}