#include "MyPoint.h"
#include<iostream>
#include<math.h>

using namespace std;

MyPoint::MyPoint() {
	mPosX = 0;
	mPosY = 0;

}


MyPoint::MyPoint(int _mPosX, int _mPosY) {
	mPosX = _mPosX;
	mPosY = _mPosY;
}


void MyPoint::Display() {

	cout << "Value of mPosX is :" << mPosX << endl;
	cout << "Value of mPosY is :" << mPosY << endl;
}

void MyPoint::SetX(int X) {
	this->mPosX = X;
}

int MyPoint::GetX() {
	return this -> mPosX;
}

void MyPoint::SetY(int Y) {
	this->mPosY = Y;
}

int MyPoint::GetY() {
	return this->mPosY;
}

double MyPoint::Distance(MyPoint p) {
	double a = (this->mPosX - p.mPosX);
	double b = (this->mPosY - p.mPosY);
	return sqrt(a*a +b*b);
}
