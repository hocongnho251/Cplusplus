#include "Patient.h"
#include<ctime>
#include"FluVirus.h"
#include"DengueVirus.h"
#include"MyVirus.h"
#include<iostream>

using namespace std;

Patient::Patient()
{
	this->m_resistance = InitResistance();
	cout << "Blood of Patient is:" << m_resistance << endl;
	this->DoStart();

}


Patient::~Patient()
{
}

int Patient::InitResistance() {
	
	return rand() % 8001 + 1000;
}
void Patient::DoStart() {
	this->m_stage = 1;
	int totalVirus = rand() % 11 + 10;
	MyVirus* virus;
	for (int i = 0; i < totalVirus; i++) {
		int typeofVirus = rand() % 2;
		if (typeofVirus == 0) {
			virus = new FluVirus();
			m_virusList.push_back(virus);
		}
		else {
			virus = new DengueVirus();
			m_virusList.push_back(virus);
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance) {
	int totalResistance =0;
	for(auto virus: m_virusList){
		
		
		if (virus->ReduceReistance(medicine_resistance) <= 0) {
			virus->DoDie();
			delete virus;
			m_virusList.remove(virus);
		}
		else {
			list<MyVirus*>::iterator postion;
			(*postion) = virus;
			list<MyVirus*> listTemp;
			listTemp = virus->DoClone();
			m_virusList.insert(m_virusList.begin(), listTemp.begin(), listTemp.end());
		}
	}
	for (auto virus : m_virusList) {
		totalResistance += virus->Getm_resistance();
	}
	if (InitResistance() < totalResistance) {

		this->DoDie();
		cout << "Patient was die";

	}
	else {
		cout << "Patient Live";
	}
}

void Patient::DoDie() {
	this->m_virusList.clear();
	this->m_stage = 0;

}