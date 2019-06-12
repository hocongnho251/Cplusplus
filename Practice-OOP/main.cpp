#include"MyPoint.h"
#include <iostream>
#include<math.h>

using namespace std;

void main() {
	MyPoint* myPoint = new MyPoint(1,2);
	MyPoint* myPoint2 = new MyPoint(2,2);
	cout << myPoint->Distance(*myPoint2);

	system("pause");



}