#include"MyPoint.h"
#include <iostream>
#include<math.h>

using namespace std;

void main() {

	int a, b;
	MyPoint* myPoint1 = new MyPoint() ;
	MyPoint* myPoint2 = new MyPoint(3,3);
	cout << "Put value for point 1 (x,y) :"<<endl;
	cin >> a;
	myPoint1->SetX(a);
	cin >> b;
	myPoint1->SetY(b);
	
	cout << "Distance between point 1 and point 2 :"<<myPoint1->Distance(*myPoint2)<<endl;


	system("pause");



}