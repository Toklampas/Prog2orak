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
	cout << "K�lcs�nz�si ar�ny: " << (double)cppMaster << endl; //0.4 az �rt�k, ha 2 p�ld�nytk�lcs�n�ztek ki
	//A "C++ Alapok" c�m� k�nyv p�ld�nysz�ma 3, nincs k�lcs�nz�tt p�ld�ny
	++cppBasics; //1 p�ld�nyt k�lcs�n�ztek ki
	cout << "K�lcs�nz�si ar�ny: " << (double)cppBasics << endl; //0.333...
	//�tvezetj�k a k�lcs�nz�seket a mesterfokra:
	cppMaster += cppBasics;
	cout << "K�lcs�nz�si ar�ny (mesterfokon): " << (double)cppMaster << endl; //0.6, 3 p�ld�ny k�lcs�n�zve 5 - b�l
	cout << "K�lcs�nz�si ar�ny (alapok): " << (double)cppBasics << endl; //0, nincs m�r k�lcs�nz�ttp�ld�ny
	return 0;
}