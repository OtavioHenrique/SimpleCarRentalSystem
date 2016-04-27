#include <iostream>
#include <cstdlib>
#include "Client.h"
#define MAX 10

using namespace std;

#ifndef ClientDB_h
#define ClientDB_h

class ClientDB
{
	private:
		Client * customers[MAX];

	public:
		ClientDB();
		int include(string, string, string, string); // add client, return 1 if sucess or 0 if failed 
		int exclude(string); // erase client, return 1 if sucess or 0 if failed (according to the CPF)
		void listar(); // list of clients
		~ClientDB();
	
};

#endif