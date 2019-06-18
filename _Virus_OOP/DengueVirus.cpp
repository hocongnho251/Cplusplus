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
	this->DoDie();
}

DengueVirus::DengueVirus(DengueVirus* denguaVirus) {
	this->m_protein[4] = denguaVirus->m_protein[4];
	this->m_dna = denguaVirus->m_dna;
	this->m_resistance = denguaVirus->m_resistance;
}

void DengueVirus::DoBorn() {
	this->LoadADNInformation();
	m_protein[0] = 'NS5';
	m_protein[1] = 'NS3';
	m_protein[2] = 'E';
}

list<MyVirus*> DengueVirus::DoClone() {
	DengueVirus *dengue1 = new DengueVirus(this);
	DengueVirus *dengue2 = new DengueVirus(this);
	list<MyVirus*> listDengue;
	listDengue.push_back(dengue1);
	listDengue.push_back(dengue2);
	return listDengue;

}

void DengueVirus::DoDie() {

}

void DengueVirus::InitResistance() {
		//srand(time(NULL));
		int i=rand() % 3;
		if (i==0) {
			this->m_resistance = rand() % (20 + 1 - 11)+11;
			cout << "Resistance of NS5:" << this->m_resistance << endl;
		}
		else if (i == 1) {
			this->m_resistance = rand() % (10 + 1 - 1)+1;
			cout << "Resistance of NS3:" << this->m_resistance << endl;
		}
		else {
			this->m_resistance = rand() % (30 + 1 - 21)+21;
			cout << "Resistance of E:" << this->m_resistance << endl;
		}

	
}


