#include <iostream>
#include <cstdlib>
#include "../includes/Vehicle.h"

using namespace std;

Vehicle::Vehicle(string color, string licensePlate)
{
	setColor(color);
	setLicensePlate(licensePlate);
}

void Vehicle::setColor(string color)
{
	this->color = color;
}

void Vehicle::setLicensePlate(string licensePlate)
{
	this->licensePlate = licensePlate;
}

string Vehicle::getColor()
{
	return color;
}

string Vehicle::getLicensePlate()
{
	return licensePlate;
}

void Vehicle::print()
{
	cout<<"-----------------"<<endl;
	cout<<"Color: "<<getColor()<<endl;
	cout<<"License Plate: "<<getLicensePlate()<<endl;
	cout<<"-----------------"<<endl;
}