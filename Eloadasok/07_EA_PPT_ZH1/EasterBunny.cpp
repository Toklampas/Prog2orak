#include <stdio.h>
#include <iostream>

using namespace std;

class  Egg {
	unsigned weight;
public:
	Egg(unsigned pweight=0) : weight(pweight) {};
	unsigned getWeight() const { return weight; }
	bool operator==(const Egg& theOther) const{
		return weight == theOther.getWeight();
	}

};

class EasterBunny {
	unsigned eggCount;
	Egg* eggs;
public:
	EasterBunny() : eggCount(0), eggs(nullptr) {}
	~EasterBunny() {
		delete[] eggs;
	}
	EasterBunny(const EasterBunny& other)
	{
		if (other.eggCount == 0)
		{
			eggCount = 0;
			eggs = nullptr;
		}
		else {

			eggCount = other.eggCount;
			eggs = new Egg[eggCount];
			for (unsigned i = 0; i < eggCount; i++)
				eggs[i] = other.eggs[i];
		}
	}


	Egg& operator[](unsigned index) const {
		return eggs[index];
	}

	bool isElement(const Egg& tojci)  const {
		for (unsigned i = 0; i < eggCount; i++) {
			if (eggs[i] == tojci)
				return true;
		}
		return false;
	}

	EasterBunny& operator+=(const Egg& tojci) {

		if (!isElement(tojci)) {
			Egg* temp = new Egg[eggCount + 1];
			for (unsigned i = 0; i < eggCount; i++) {
				temp[i] = eggs[i];
			}
			temp[eggCount] = tojci;
			delete[] eggs;
			eggs = temp;
			eggCount++;
		}

		return *this;
	}

	EasterBunny operator+(const EasterBunny& other) {
		EasterBunny newBunny = *this;
		
		for (unsigned i = 0; i < other.eggCount; i++)
			newBunny+= other.eggs[i];
		
		return newBunny;
	}


	bool operator==(const EasterBunny& theOther) const {
		if (eggCount != theOther.eggCount)
			return false;
		for (unsigned i = 0; i < eggCount; i++)
			if (!theOther.isElement(eggs[i]))
				return false;
		return true;
	}

	EasterBunny& operator=(const EasterBunny& other) {
		if (this == &other) return *this;

		delete[] eggs;
		if (other.eggCount == 0)
		{
			eggCount = 0;
			eggs = nullptr;
			return *this;
		}
		eggCount = other.eggCount;
		eggs = new Egg[eggCount];
		for (unsigned i = 0; i < eggCount; i++)
			eggs[i] = other.eggs[i];
		return *this;


	}


	unsigned getEggCount() const { return eggCount; }


};

ostream& operator<<(ostream& os, const EasterBunny& nyuszo) {
	unsigned eggCount = nyuszo.getEggCount();
	os << "Nyuszika " << eggCount << "  tojassal, sulyuk: ";
	for (unsigned i = 0; i < eggCount; i++)
		os << nyuszo[i].getWeight()<<' ';

	return os;
}

int main(int argc, char* argv[]) {

	Egg redEgg(9);
	Egg glitterEgg(27);
	Egg greenEgg(42);

	EasterBunny bunny1;
	EasterBunny bunny2;
	bunny1+=(redEgg);
	bunny1 += (greenEgg);
	bunny2 += (glitterEgg);
	bunny2 += (greenEgg);

	cout << bunny1 << endl;
	cout << bunny2 << endl;

	EasterBunny bunny;
	bunny = bunny1 + bunny2;

	cout << bunny << endl;	// 9 42 27 !!!!

	if (bunny1 == bunny2)
		cout << "Twins." << endl;

	bunny1 = bunny2;
	if (bunny1 == bunny2)
		cout << "Twins." << endl;


	getchar();
	return 0;

}