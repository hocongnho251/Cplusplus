#pragma once
class MyPoint {
private:
	int mPosX;
	int mPosY;
public:

	MyPoint();//default constructor
	MyPoint(int _mPosX, int _mPosY); //parameter constructor
	void Display();
	void SetX(int X);
	int GetX();
	void SetY(int Y);
	int GetY();
	double Distance(MyPoint p);// Distance between 2 point

};