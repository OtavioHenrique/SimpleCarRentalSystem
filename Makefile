all: SimpleCarRentalSystem

SimpleCarRentalSystem: Main.o AdminDB.o Employee.o EmployeeDB.o LoginADM.o Pessoa.o
	@g++ Main.o AdminDB.o Employee.o EmployeeDB.o LoginADM.o Pessoa.o -o Main
	@echo Compiling..

Main.o: src/Main.cpp
	@g++ -c src/Main.cpp
	@echo Compiling Main.cpp..

AdminDB.o: src/AdminDB.cpp
	@g++ -c src/AdminDB.cpp
	@echo Compiling AdminDB.cpp..

Employee.o: src/Employee.cpp
	@g++ -c src/Employee.cpp
	@echo Compiling Employee.cpp..

EmployeeDB.o: src/EmployeeDB.cpp
	@g++ -c src/EmployeeDB.cpp
	@echo Compiling EmployeeDB.cpp..

LoginADM.o: src/LoginADM.cpp
	@g++ -c src/LoginADM.cpp
	@echo Compiling LoginADM.cpp..

Pessoa.o: src/Pessoa.cpp
	@g++ -c src/Pessoa.cpp
	@echo Compiling Pessoa.cpp

clean:
	rm -rf *o SimpleCarRentalSystem