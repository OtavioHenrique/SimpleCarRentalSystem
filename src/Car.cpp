#include <iostream>
#include <cstdlib>
#include "../includes/Car.h"

using namespace std;

Car::Car(string car, string color, string licensePlate, int year) : Vehicle(color, licensePlate, year)
{
	setCar(car);
	rent = NULL;
}

void Car::setCar(string car)
{
	this->car = car;
}

string Car::getCar()
{
	return car;
}

void Car::rentCar(Client* client)
{
	rent = client;
}

void Car::releaseCar()
{
	rent = NULL;
}

void Car::printAll()
{
	cout<<"-----------------"<<endl;
	cout<<"Car: "<<getCar()<<endl;
	print();
	if(rent != NULL)
		rent->print();
	cout<<"-----------------"<<endl;
}

Car::~Car()
{
	
}