#pragma once
class MyPoint {
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int _mPosX, int _mPosY);
	void Display();
	void SetX(int X);
	int GetX();
	void SetY(int Y);
	int GetY();
	double Distance(MyPoint p);

};