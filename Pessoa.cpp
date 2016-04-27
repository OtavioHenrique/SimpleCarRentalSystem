#include "bin/Pessoa.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Constructor
Pessoa::Pessoa(string name,string cpf, string RG)
{
	setName(name);
	setCpf(cpf);
	setRG(RG);
}

//Functions Set

void Pessoa::setName(string name)
{
	this->name = name;
}

void Pessoa::setCpf(string cpf)
{
	this->cpf = cpf;
}

void Pessoa::setRG(string RG)
{
	this->RG = RG;
}

//Functions Get

string Pessoa::getName()
{
	return name;
}

string Pessoa::getCpf()
{
	return cpf;
}

string Pessoa::getRG()
{
	return RG;
}

//others functions

void Pessoa::print()
{
	cout<<"Nome: "<<getName()<<endl;
	cout<<"Cpf: "<<getCpf()<<endl;
	cout<<"RG: "<<getRG()<<endl;
}

Pessoa::~Pessoa()
{
	
}