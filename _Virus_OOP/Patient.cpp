#include "Patient.h"
#include<ctime>
#include"FluVirus.h"
#include"DengueVirus.h"

Patient::Patient()
{

}


Patient::~Patient()
{
}

int Patient::InitResistance() {
	srand(time(NULL));
	return rand() % 8001 + 1000;
}
void Patient::DoStart() {
	m_stage = 1;
	srand((time(NULL)));
	int totalVirus = rand() % 11 + 10;
	for (int i = 0; i < totalVirus; i++) {
		int typeofVirus = rand() % 2;
		if (typeofVirus == 0) {
			FluVirus* flu = new FluVirus();
			m_virusList.push_back(flu);
		}
		else {
			DengueVirus* dengue = new DengueVirus();
			m_virusList.push_back(dengue);
		}
	}
}

void Patient::TakeMedicine() {
	while (m_stage == 1)
	{
		for (int i = 0; i < m_virusList.size(); i++) {
			
		}
	}
}