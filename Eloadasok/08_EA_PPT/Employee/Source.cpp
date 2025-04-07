#include <stdio.h>
#include <iostream>

using namespace std;

class Person {
	string name;
	int birthyear;
public:
	Person(string pname, int pBirthYear) : name(pname), birthyear(pBirthYear)
	{}
	void Print()
	{
		cout << name.c_str() << ',' << birthyear << endl;
	}

};

class Employee : public Person {
	int employmentYear;
public:


	void setEmploymentYear(int param) { employmentYear = param; }

	//Hogy irassuk ki az extra informaciot?
	void Print() {
		//OK, vegulis meghivja az ososztalybelit, de nem az igazi, ket kulon sor lesz
		Person::Print();
		cout << employmentYear << endl;
		//A jovo heten talalunk erre jobb megoldast.
	}

	//Mi legyen a kosntruktor? Az ora vegere kiderultÉ csak inicializacios listaval fog menni
	Employee(string pname, int pBirthYear, int pEmploymentYear)
		: Person(pname, pBirthYear), employmentYear(pEmploymentYear)
	{}
};


int main(int argc, char* argv[]) {



	getchar();
	return 0;

}