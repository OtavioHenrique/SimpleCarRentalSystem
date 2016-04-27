#include <iostream>
#include <cstdlib>
#include "../includes/Client.h"

using namespace std;

Client::Client(string nome, string cpf, string RG, string codClient):Pessoa(nome, cpf, RG)
{
	setCodClient(codClient);
}

void Client::setCodClient(string codClient)
{
	this->codClient = codClient;
}