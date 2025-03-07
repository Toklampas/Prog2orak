#pragma once
class Circle
{
private:
	//A kor kozepe
	int x;
	int y;
	//A kor sugara
	int radius;

public:

	Circle();
	~Circle();

	//Ugyanaz, mit Pointnal. Lesz erre jobb otletunk kesobb (orokles)
	int getX() { return x; }
	int getY() { return y; }
	int getRadius() { return radius; }
	void setX(int xparam);
	void setY(int yparam);
	void setRadius(int radiusParam);

	void draw();

};

