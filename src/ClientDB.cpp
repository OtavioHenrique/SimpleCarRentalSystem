#include <iostream>
#include <cstdlib>
#define MAX 10
#include "../includes/ClientDB.h"

using namespace std;

ClientDB::ClientDB()
{
	int i;
	for (int i = 0; i < MAX; i++)
	{
		customers[i] = NULL;
	}
}

int ClientDB::include(string name, string cpf, string RG, string code)
{
	int i;
	for(i=0;i<MAX;i++)
	{
		if(customers[i] == NULL )
		{
			customers[i] = new Client(name,cpf,RG,code);
			return 1;
		}	
	}

	return 0;
}

int ClientDB::exclude(string cpf)
{
	int i;
	for (int i = 0; i < MAX; i++)
	{
		if(customers[i] != NULL )
		{
			if(customers[i]->getCpf() == cpf )
			{
				delete( customers[i] );
				customers[i] = NULL;
				return 1;
			}
		}
	}

	return 0;
}

void ClientDB::listar()
{
	int i;
	for (int i = 0; i < MAX; i++)
	{
		if(customers[i] != NULL )
		{
				cout<<"-----------------------"<<endl;
				customers[i]->print();
				cout<<"-----------------------"<<endl;
		}
	}
}

ClientDB::~ClientDB()
{
	
}