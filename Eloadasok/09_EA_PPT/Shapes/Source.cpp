#include <stdio.h>
#include <iostream>

using namespace std;



class Shape {

public:
	virtual void Print() { cout << "Shape" << endl; }
	virtual double area() = 0;
	void PrintArea() { cout << " Area: " << area() << endl; }

};

class Circle :public Shape{
	double r;
public:
	Circle(double pr) :r(pr) {}
	void Print() { cout << "Circle" << endl; }
	double area() { return r*r*3.14159265359; }
};

class Rectangle : public Shape {
	double a, b;
public:
	Rectangle(double pa, double pb) :a(pa), b(pb) {}
	void Print() { cout << "Rectangle" << endl; }
	void setA(double param) { a = param; }
	void setB(double param) { b = param; }
	double area() { return a*b; }
};

class Square : private Rectangle {
public:
	Square(double pa) :Rectangle(pa, pa) {}
	void Print() { cout << "Square" << endl; }
	void setA(double pa) { Rectangle::setA(pa); Rectangle::setB(pa); }

};
int main(int argc, char* argv[]) {

	Shape* shapes[3];
	shapes[0] = new Rectangle(20.0, 5.0);
	shapes[1] = new Circle(5.641895);
	shapes[2] = (Shape*) new Square(10.0);

	for (int i = 0; i < 3; i++) {
		shapes[i]->Print();
		shapes[i]->PrintArea();
		delete shapes[i];
	}

	getchar();
	return 0;

}