#include"Patient.h"
#include<ctime>
#include"FluVirus.h"
#include"DengueVirus.h"
#include"MyVirus.h"
#include<iostream>
#include<Windows.h>

using namespace std;


Patient::Patient()
{
	this->m_resistance = InitResistance();
	cout << "Blood of Patient is:" << m_resistance << endl;
	this->DoStart();

}


Patient::~Patient()
{
	this->DoDie();

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
			Sleep(500);
			virus = new FluVirus();
			m_virusList.push_back(virus);	
		}
		else {
			virus = new DengueVirus();
			Sleep(500);
			m_virusList.push_back(virus);
	
		}
	}
	
}


void Patient::TakeMedicine(int medicine_resistance) {
	int totalResistance =0;

	for (auto position = m_virusList.begin();position!=m_virusList.end();){
	
		if ((*position)->ReduceReistance(medicine_resistance) <= 0) {
			(*position)->DoDie();
			delete (*position);
			position = this->m_virusList.erase(position);
		}
		else {
			list<MyVirus*> listTemp;
			listTemp = (*position)->DoClone();
			m_virusList.insert(position, listTemp.begin(), listTemp.end());

			++position;
		}
	}

	for (auto v : m_virusList) {
		totalResistance += (v)->Getm_resistance();
	}

	if (InitResistance() < totalResistance) {
		this->DoDie();
		
		cout << "Patient was die"<<endl;

	}
	else {
		cout << "Patient Live"<<endl;
	}
}


void Patient::DoDie() {
	this->m_stage = 0;
	for (list<MyVirus*>::iterator i = m_virusList.begin(); i != m_virusList.end();i++) {
		delete *i;
	}
	m_virusList.clear();

}