#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef Vehicle_h
#define Vehicle_h

class Vehicle
{
	private:
		string color, licensePlate;

	public:
		Vehicle(string,string);

		//functions set
		void setColor(string);
		void setLicensePlate(string);

		//functions get
		string getColor();
		string getLicensePlate();

		void print();

		~Vehicle();
	
};

#endif