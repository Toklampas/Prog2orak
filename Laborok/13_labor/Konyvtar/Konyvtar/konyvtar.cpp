#include <string>
#include <iostream>

using namespace std;

class Book {
	const string title;
	int copies;
	int borrowed;

public:
	Book(const string pTitle, int pCopies, int pBorrowed)
		: title(pTitle), copies(0), borrowed(pBorrowed)
	{
		if (pCopies < 1) copies = 0;
		else copies = pCopies;
	}
	
	string getTitle() const { return title; }
	int getBorrowed() const { return borrowed; }
	int getCopies() const { return copies; }

	Book& operator++(){
		if (borrowed < copies)
			++borrowed;
		return *this;
	}

	operator double() const {
		return static_cast<double>(borrowed) / static_cast<double>(copies);
	}

	Book& operator+=(Book& other) {
		int szabad = copies - borrowed;
		int atviheto = (other.borrowed < szabad) ? other.borrowed : szabad;
		borrowed += atviheto;
		other.borrowed -= atviheto;
		if (other.borrowed < 0) other.borrowed = 0;
		return *this;
	}
};

int main()
{
	Book cppMaster("C++ Mesterfokon", 5, 0);
	Book cppBasics("C++ Alapok", 3, 0);
	++(++cppMaster);
	cout << "Kölcsönzési arány: " << (double)cppMaster << endl; //0.4 az érték, ha 2 példánytkölcsönöztek ki
	//A "C++ Alapok" címû könyv példányszáma 3, nincs kölcsönzött példány
	++cppBasics; //1 példányt kölcsönöztek ki
	cout << "Kölcsönzési arány: " << (double)cppBasics << endl; //0.333...
	//Átvezetjük a kölcsönzéseket a mesterfokra:
	cppMaster += cppBasics;
	cout << "Kölcsönzési arány (mesterfokon): " << (double)cppMaster << endl; //0.6, 3 példány kölcsönözve 5 - bõl
	cout << "Kölcsönzési arány (alapok): " << (double)cppBasics << endl; //0, nincs már kölcsönzöttpéldány
	return 0;
}