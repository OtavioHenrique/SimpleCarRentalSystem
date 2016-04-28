#include <iostream>
#include <cstdlib>
#include "../includes/Car.h"

using namespace std;

Car::Car(string car, string color, string licensePlate, int year) : Vehicle(color, licensePlate, year)
{
	setCar(car);
	rentedCar = "";
}

void Car::setCar(string car)
{
	this->car = car;
}

string Car::getCar()
{
	return car;
}

void Car::rentCar(string client)
{
	rentedCar = client;
}

void Car::releaseCar()
{
	rentedCar = "";
}

void Car::printAll()
{
	cout<<"-----------------"<<endl;
	cout<<"Car: "<<getCar()<<endl;
	print();
	if(rentedCar != "")
		rentedCar->print();
	cout<<"-----------------"<<endl;
}

int Car::availability()
{
	if(rentedCar != "")
		return 0;
	else
		return 1;
}

Car::~Car()
{
	
}