#include <stdio.h>
#include <iostream>

using namespace std;


class A {
public:
		int a;
		//int b;
		//void f() { cout << "A->f" << endl; }
};

class B {
public:
	int b; 
	void f() { cout << "B->f" << endl; } //es f-je
};

class C : public A, public B {
public: 
	int c;
};
int main(int argc, char* argv[]) {

	C c;
	C* pc = &c;
	B* pb = &c;
	A* pa = &c;

	pa->a = 10; //OK
	//pa->b = 10; //hiba
	//pb->a = 20; //hiba
	pb->b = 20; //ok

	//Ez egy keresztbe cast. Lefordul, de az eltolas miatt rosszul mukodik.
	((A*)pb)->a = 123;
	cout << c.a; // nem 123 lesz!

	A* pa2 = (A*)(C*) pb; //a szulore felcastolva mar jo. Az A* castot ki sem kellene irni.

	getchar();
	return 0;

}