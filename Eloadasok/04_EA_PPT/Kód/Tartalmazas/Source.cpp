#include <stdio.h>
#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

class Person
{

	char* name;
	Person* father;
public:
	Person(char* nameparam, Person* theFather = 0);
	Person(const Person& theOther);
	~Person();
	void doNothing(int a);
	char* getName() { return name; }

private:

};


Person::Person(char * nameparam, Person* theFather)
{
	name = new char[strlen(nameparam) + 1];
	strcpy(name, nameparam);
	father = theFather;
}

Person::Person(const Person & theOther)
{
	name = new char[strlen(theOther.name) + 1];
	strcpy(name, theOther.name);
	printf("copy!\n");
}

Person::~Person()
{
	printf("Killed: %s RIP\n", name);
	delete[] name;
}

void kick(Person subject) {
	printf("Kicked: %s\n", subject.getName());
}

void doIt()
{
	Person daddy("Daddy");

	Person pisti("Pisti", &daddy);
	Person iker = pisti;
	kick(pisti);

}

int main(int argc, char* argv[]) {


	doIt();
	getchar();
	return 0;

}