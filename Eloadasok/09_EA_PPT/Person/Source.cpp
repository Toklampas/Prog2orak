#include <stdio.h>
#include <iostream>

using namespace std;

class Person {
	string name;
	int birthYear;
public:
	Person(string pname, int pB) :name(pname), birthYear(pB) {}
	int getBirthYear() const { return birthYear; }
};

class Employee : public Person {
	int employmentYear;
public:
	Employee(string pname, int pB) :Person(pname, pB) {}

};

class Student :public Person {
	int enrollmentYear;
public:
	Student(string pname, int pB) :Person(pname, pB) {}

};

bool isFrom20Century(const Person& p)
{
	return (p.getBirthYear() < 2000);
}


int main(int argc, char* argv[]) {

	Employee rector("Jozsa Janos", 1957);
	Student laszlo("Banyasz Laszlo", 1999);

	cout << "Rector is from the 20th century: " << isFrom20Century(rector) << endl;
	cout << "Laci is from the 20th century: " << isFrom20Century(laszlo)<<endl;


	getchar();
	return 0;

}