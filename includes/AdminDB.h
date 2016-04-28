#include <iostream>
#include <string>
using std::string;
#include "Pessoa.h"
#ifndef ADMINDB_H 
#define ADMINDB_H

#include "Admin.h" 
using namespace std;

class AdminDB : public Pessoa {
	private:
		Admin *p;
		int existe (string login){
			int i = 0;
			for (i=0; i<10; i++){
				if (p[i].getLogin() == login){
					return i;
				}
			}
			return -1;
		}

	public:
		AdminDB();
		int incluir (string, string, string, string, string);
		int excluir (string);
		Admin Authentication(Admin);
		void listar();
		~AdminDB();
};

#endif
