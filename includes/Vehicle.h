#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef Vehicle_h
#define Vehicle_h

class Vehicle
{
	private:
		string color, licensePlate;
		int year;

	public:
		Vehicle(string,string, int);

		//functions set
		void setColor(string);
		void setLicensePlate(string);
		void setYear(int);

		//functions get
		string getColor();
		string getLicensePlate();
		int getYear();

		void print();

		~Vehicle();
	
};

#endif