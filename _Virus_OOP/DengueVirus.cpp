#include "DengueVirus.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include"Patient.h"


DengueVirus::DengueVirus(){
	this->DoBorn();
	this->InitResistance();
}


DengueVirus::~DengueVirus(){
}

DengueVirus::DengueVirus(DengueVirus* denguaVirus) {
	this->m_protein[4] = denguaVirus->m_protein[4];
	this->m_dna = denguaVirus->m_dna;
	this->m_resistance = denguaVirus->m_resistance;
}

void DengueVirus::DoBorn() {
	LoadADNInformation();
	m_protein[0] = 'NS5';
	m_protein[1] = 'NS3';
	m_protein[2] = 'E';
}

list<MyVirus*> DengueVirus::DoClone() {
	DengueVirus *dengue = new DengueVirus();
	list<MyVirus*> listDengue;
	listDengue.push_back(dengue);
	return listDengue;

}

void DengueVirus::DoDie() {
	if (!this)
		delete this;
}

void DengueVirus::InitResistance() {
		srand(time(NULL));
		int i=rand() % 3;
		if (m_protein[i] == 'NS5') {
			this->m_resistance = rand() % (20 + 1 - 11)+11;
		}
		else if (m_protein[i] == 'NS3') {
			this->m_resistance = rand() % (10 + 1 - 1)+1;
		}
		else {
			this->m_resistance = rand() % (30 + 1 - 21)+21;
		}

	
}


