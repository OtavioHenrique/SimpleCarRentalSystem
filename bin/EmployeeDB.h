#include <iostream>
#include <string>
using std::string;

#ifndef EMPLOYEEDB_H 
#define EMPLOYEEDB_H

#include "Employee.h" 
using namespace std;

class EmployeeDB {
	private:
		Employee *p;
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
		EmployeeDB();
		int incluir (string, string, string);
		int excluir (string);
		Employee Authentication(Employee);
		void listar();
		~EmployeeDB();
};

#endif