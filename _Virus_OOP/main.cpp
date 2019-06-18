#include <stdio.h>
#include <cstdlib>
#include"Patient.h"
#include<iostream>
#include<ctime>
#include "vld.h"
using namespace std;
int main()
{
	srand(time(NULL));
	Patient p;
	int t = 0;
	while (p.m_stage == 1)
	{
		cout<<("Take Medicine (0 = NO, 1 = YES)")<<endl;
		cin >> t;
		if (t == 1)
		{
			int min = 1;
			int max = 5;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "****Medicine-Resistance is " << medicine_resistance<<endl;
			p.TakeMedicine(medicine_resistance);
			

		}
	}
	system("pause");
}