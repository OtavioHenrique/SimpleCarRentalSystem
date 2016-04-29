all: SimpleCarRentalSystem

SimpleCarRentalSystem: Main.o AdminDB.o Employee.o EmployeeDB.o LoginADM.o Pessoa.o Client.o ClientDB.o Car.o CarDB.o Vehicle.o Motocycle.o MotocycleDB.o
	@g++ Main.o AdminDB.o Employee.o EmployeeDB.o LoginADM.o Pessoa.o Client.o ClientDB.o Car.o CarDB.o Vehicle.o Motocycle.o MotocycleDB.o -o Main

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

Client.o: src/Client.cpp
	@g++ -c src/Client.cpp
	@echo Compiling Client.cpp..

ClientDB.o: src/ClientDB.cpp
	@g++ -c src/ClientDB.cpp
	@echo Compiling ClientDB.cpp..

Car.o: src/Car.cpp
	@g++ -c src/Car.cpp
	@echo Compiling Car.cpp..

Vehicle.o: src/Vehicle.cpp
	@g++ -c src/Vehicle.cpp
	@echo Compiling Vehicle.cpp..	

CarDB.o: src/CarDB.cpp
	@g++ -c src/CarDB.cpp
	@echo Compiling CarDB.cpp..

Motocycle.o: src/Motocycle.cpp
	@g++ -c src/Motocycle.cpp
	@echo Compiling Motocycle.cpp..

MotocycleDB.o: src/MotocycleDB.cpp
	@g++ -c src/MotocycleDB.cpp
	@echo Compiling MotocycleDB.cpp..

clean:
	rm -rf *o SimpleCarRentalSystem
