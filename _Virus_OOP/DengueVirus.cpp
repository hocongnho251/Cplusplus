#include "DengueVirus.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


DengueVirus::DengueVirus(){
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

}


