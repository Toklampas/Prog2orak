#include <stdio.h>
#include <iostream>

using namespace std;


class Vector {
private:
	double x;
	double y;
public:
	Vector(double px, double py) : x(px), y(py) {}
	friend double vectorLength(Vector);
	friend class VectorPrinter;
};

class VectorPrinter {
	Vector v;
public:
	VectorPrinter(Vector pv) : v(pv) {
		printf("x: %lf, y: %;f\n", v.x, v.y);
	}
};

//globalis fuggveny
//Persze ez nem szep pelda igy, adatrejtest kijatssza, getterrel kellene megcsinalnunk. Csak illusztracio.
double vectorLength(Vector v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

int main(int argc, char* argv[]) {

	Vector v(3.0, 4.0);
	printf("V hossza: %lf\n", vectorLength(v));

	getchar();
	return 0;

}