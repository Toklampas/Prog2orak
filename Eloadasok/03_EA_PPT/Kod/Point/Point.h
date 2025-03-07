#pragma once
class Point
{
private:
	int x;
	int y;

public:
	Point();
	Point(int xparam, int yparam);
	Point(const Point& theOther);

	~Point();

	int getX() { return x; }
	int getY() { return y; }
	void setX(int xparam);
	void setY(int yparam);

	void draw();


};

