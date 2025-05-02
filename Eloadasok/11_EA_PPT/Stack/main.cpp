#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

template <int DIM=3>
class HyperCube {
	const int dimensions;
	int origo[DIM];
public:
	HyperCube() : dimensions(DIM) {}

	template <class UBUL>
	UBUL getVerticesCount() {
		UBUL result = pow(2, dimensions);
		return result;
	}

};


int main(int argc, char* argv[]) {

	HyperCube<2> square;
	const int haromde = 3;
	HyperCube<> cube;

	long alma = cube.getVerticesCount<long>();

	getchar();
	return 0;

}