// ha nem includeolnánk, nem ismerné a fordító a Person deklarációt
#include "person.h"

#include <cstdio>
#include <cstring>


// Ez a konstruktor nulláz mindent
Person::Person() {
	printf("Default konstruktor lefut\n");
	name = nullptr;
	age = 0;	
}

// - ha mindkét paraméternek lenne default értéke, akkor nem kellene definiálni külön alapértelmezett konstruktort
Person::Person(const char* name, unsigned int age) {
	printf("Parameteres konstruktor lefut\n");
	this->name = nullptr;
	this->setName(name);
	this->age = age;
}

//Másolókontruktor, ezzel tudunk lemásolni egy már létező objektumot
Person::Person(const Person& p)  {
	printf("Copy konstruktor lefut\n");
	this->name = nullptr;
	//Itt mély másolat készül! Gondold meg: Bitröl bitre másolás miért nem lenne jó?
	this->setName(p.name);
	this->age = p.age;
}


// Ha van dinamikus tagváltozó, akkor kell destruktor is
// amit lefoglalsz, szabadítsd is fel!
Person::~Person() {
	printf("%s\tdestruktor lefut\n", name);
	// - ha nem adnánk értéket a this->name-nek (a null is értéknek számít), undefined behavior hibával kilépne a program
	// - bármilyen dinamikusan foglalt tömbről is van szó (függetlenül a tartalmától) delete[]-tel kell felszabadítani
	// - ha nem tömb, akkor delete
	delete[] this->name;
}

const char* Person::getName() {
	printf("%s\tgetName lefut\n", name);
	return name;
}

void Person::setName(const char* name) {
	printf("setName lefut\n");
	delete[] this->name;
	this->name = new char[strlen(name) + 1]; // +1 a null terminátornak
	strcpy(this->name, name);
}

unsigned int Person::getAge() {
	printf("%s\tgetAge lefut\n", name);
	return this->age;
}

void Person::setAge(const unsigned int age) {
	printf("%s\tsetAge lefut\n", name);
	this->age = age;
}