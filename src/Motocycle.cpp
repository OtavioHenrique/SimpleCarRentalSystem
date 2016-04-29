#include <iostream>
#include <cstdlib>
#include "../includes/Motocycle.h"

using namespace std;

Motocycle::Motocycle(string Motocycle, string color, string licensePlate, int year) : Vehicle(color, licensePlate, year)
{
	setMotocycle(Motocycle);
	rentedMotocycle = NULL;
}

void Motocycle::setMotocycle(string motocycle)
{
	this->motocycle = motocycle;
}

void Motocycle::setRentedMotocycle(Client* rentedMotocycle)
{
	this->rentedMotocycle = rentedMotocycle;
}

string Motocycle::getMotocycle()
{
	return motocycle;
}

Client* Motocycle::getRentedMotocycle()
{
	return rentedMotocycle;
}


void Motocycle::rentMotocycle(Client* client)
{
	setRentedMotocycle(client);
}

void Motocycle::releaseMotocycle()
{
	rentedMotocycle = NULL;
}

void Motocycle::printAll()
{
	cout<<"-----------------"<<endl;
	cout<<"Motocycle: "<<getMotocycle()<<endl;
	print();
	if(rentedMotocycle != NULL)
	{
		cout<<endl<<"Rented by: "<<endl;
		rentedMotocycle->print();
	}
	cout<<"-----------------"<<endl;
}

int Motocycle::availability()
{
	if(rentedMotocycle == NULL )
		return 1;
	else
		return 0;
}

Motocycle::~Motocycle()
{
	
}