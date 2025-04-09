#include <iostream>
#include <string>

using namespace std;

class Chocolate
{
	double weight;
	string name;
	string* ingredients;
	unsigned ingredientCount;
	static double unitPrice;
public:
	Chocolate(double weight, string name, string* ingredients, unsigned ingredientCount);
	Chocolate(const Chocolate& other);
	~Chocolate();
	double getPrice() const;
	static void setUnitPrice(double price);
	friend ostream& operator<<(ostream& os, const Chocolate& choco);

	//IMSC Feladat
	string& operator[](int);
	Chocolate& operator+=(string);

};

double Chocolate::unitPrice = 0.0;

Chocolate::Chocolate(double weight, string name, string* ingredients, unsigned ingredientCount)
{
	this->name = name;
	if (ingredientCount == 0)
	{
		this->ingredients = nullptr;
		this->ingredientCount = 0;
		this->weight = 0;
	}
	else
	{
		this->weight = weight;
		this->ingredients = new string[ingredientCount];
		this->ingredientCount = ingredientCount;
		for (unsigned i = 0; i < ingredientCount; ++i)
		{
			this->ingredients[i] = ingredients[i];
		}
	}
}

Chocolate::Chocolate(const Chocolate& other)
{
	this->name = other.name;
	delete[] this->ingredients;
	if (other.ingredientCount == 0)
	{
		this->ingredients = nullptr;
		this->ingredientCount = 0;
		this->weight = 0;
	}
	else
	{
		this->weight = other.weight;
		this->ingredients = new string[other.ingredientCount];
		for (unsigned i = 0; i < other.ingredientCount; ++i)
		{
			this->ingredients[i] = other.ingredients[i];
		}
		this->ingredientCount = other.ingredientCount;
	}
}

Chocolate::~Chocolate()
{
	if (ingredients != nullptr)
	{
		delete[] ingredients;
	}
}

double Chocolate::getPrice() const
{
	return unitPrice * weight;
}

void Chocolate::setUnitPrice(double price)
{
	unitPrice = price;
}

string& Chocolate::operator[](int num)
{
	if (num >= 0 && num < ingredientCount)
		return ingredients[num];
	else
		return ingredients[0];
}

Chocolate& Chocolate::operator+=(string ingredient)
{
	string* temp = new string[ingredientCount + 1];
	for (int i = 0; i < ingredientCount; i++)
		temp[i] = ingredients[i];
	temp[ingredientCount] = ingredient;
	if (ingredients != nullptr)
		delete[] ingredients;
	ingredients = temp;
	ingredientCount++;
	return *this;
}

ostream& operator<<(ostream& os, const Chocolate& choco)
{
	os << "Chocolate: " << choco.name << ", Weight: " << choco.weight << "g, Ingredients: ";
	for (int i = 0; i < choco.ingredientCount; ++i)
	{
		os << choco.ingredients[i];
		if (i < choco.ingredientCount - 1)
			os << ", ";
	}
	return os;
}

int main()
{
	Chocolate::setUnitPrice(20.5);
	string tomb[3] = { "Sugar", "Cocoa", "Milk" };
	Chocolate choco(100, "Bilka", tomb, 3);
	cout << choco << endl;

	//imsc tesztelése
	choco += "Mogyoro";
	choco[0] = "Cukor";
	choco[1] = "Kakao";
	choco[2] = "Tej";
	cout << choco << endl;
	choco[-1] = "Vanilia";
	cout << choco << endl;
	getchar();
	return 0;
}
