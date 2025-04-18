#include <fstream> 
#include <iostream>
#include "person.h"
#include "comparable.h" 
#include "serializable.h" 
#include "saver.h"
#include "loader.h"
#include "dog.h"
#include "sorter.h"

using namespace std;

int main()
{
	const unsigned PEOPLE_COUNT = 4;

	//Vele fogunk összehasonlítani az 1.b-ben
	Person* pisti = new Person(30, 180, 85);
	Person* people[PEOPLE_COUNT];

	people[0] = new Person(40, 182, 90);
	people[1] = new Person(12, 100, 50);
	people[2] = new Person(30, 180, 85);
	people[3] = new Person(40, 182, 90);

	//4. feladat IMSC
	Sorter::bubbleSort((Comparable**)people, 4);

	//1.a feladat tesztelése
	cout << "\tSerializing people" << endl;
	cout << "State\tIndex\tAge\tHeight\tWeight" << endl;
	for (unsigned i = 0; i < PEOPLE_COUNT; i++)
	{
		cout << "Ser.\t" << i << '\t' << *people[i] << endl;
	}

	//1.b feladat tesztelése
	cout << "\tComparing people in array with 'pisti'" << endl;
	cout << "State\tIndex\tAge\tHeight\tWeight" << endl;
	for (unsigned i = 0; i < PEOPLE_COUNT; i++)
	{
		cout << "------------------------------------" << endl; 
		cout << "Comp.\t" << i << '\t' << *people[i] << endl;
		cout << "Has the same age as Pisti? "  << (*people[i] == *pisti) << endl;
		cout << "Is younger than Pisti? " << (*people[i] < *pisti) << endl;
	}

	//2.a feladat: írd ki a people tömb elemeit a "people.txt" fájlba
	PersistenceAPI::Saver saver("people.txt");
	for (int i = 0; i < PEOPLE_COUNT; i++)
	{
		saver.save(*people[i]);
	}
	saver.close();

	//4. feladat IMSC
	PersistenceAPI::Loader loader("people.txt");
	for (int i = 0; i < PEOPLE_COUNT; i++)
	{
		loader.load(*people[i]);
	}
	loader.close();

	delete pisti;
	for (unsigned k = 0; k < PEOPLE_COUNT; k++)
		delete people[k];


	//Dogs
	const unsigned DOGS_COUNT = 4;

	Dog* alfa = new Dog("Alfa", 10);
	Dog* dogs[DOGS_COUNT];

	dogs[0] = new Dog("Beta", 9);
	dogs[1] = new Dog("Gamma", 12);
	dogs[2] = new Dog("Delta", 10);
	dogs[3] = new Dog("Epsilon", 2);

	//4. feladat IMSC
	Sorter::bubbleSort((Comparable**)dogs, 4);

	cout << "\n\n\n\tSerializing dogs" << endl;
	cout << "State\tIndex\tAge\tName" << endl;
	for (unsigned i = 0; i < DOGS_COUNT; i++)
	{
		cout << "Ser.\t" << i << '\t' << *dogs[i] << endl;
	}

	cout << "\tComparing dogs in array with 'Alfa'" << endl;
	cout << "State\tIndex\tAge\tName" << endl;
	for (unsigned i = 0; i < DOGS_COUNT; i++)
	{
		cout << "----------------------------" << endl;
		cout << "Comp.\t" << i << '\t' << *dogs[i] << endl;
		cout << "Has the same age as Alfa? " << (*dogs[i] == *alfa) << endl;
		cout << "Is younger than Alfa? " << (*dogs[i] < *alfa) << endl;
	}

	PersistenceAPI::Saver saver_d("dogs.txt");
	for (int i = 0; i < DOGS_COUNT; i++)
	{
		saver_d.save(*dogs[i]);
	}
	saver_d.close();

	//4. feladat IMSC
	PersistenceAPI::Loader loader_d("dogs.txt");
	for (int i = 0; i < DOGS_COUNT; i++)
	{
		loader_d.load(*dogs[i]);
	}
	loader_d.close();

	delete alfa;
	for (unsigned k = 0; k < DOGS_COUNT; k++)
		delete dogs[k];

	getchar();
	return 0;
}