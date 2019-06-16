#include "FluVirus.h"
#include <cstdlib>
#include <ctime>
#include<iostream>

using namespace std;



FluVirus::FluVirus()
{
	DoBorn();

}


FluVirus::~FluVirus(){
	DoDie();
}

FluVirus::FluVirus(FluVirus* fluVirus)  {
	this->m_color = fluVirus->m_color;
	this->m_resistance = fluVirus->m_resistance;
	this->m_dna = fluVirus->m_dna;

}


void FluVirus::Setm_color(int m_color) {
	
	this->m_color = m_color;
}

int FluVirus::Getm_color() {
	return this->m_color;
}

void FluVirus::DoBorn() {
	this->LoadADNInformation();
	srand(time(NULL));
	m_color = rand() % 2;
	if (m_color == 0) {
		this->Setm_color(0xff0000);//red virus
		this->Setm_resistance(InitResistance(10, 20));//set rensistance for blu virus

	}
	else {
		this->Setm_color(0x0000ff);//blu virus
		this->Setm_resistance(InitResistance(10, 15));//set rensistance for blu virus
	}
	
}

FluVirus* FluVirus::DoClone() {
	FluVirus * flu = new FluVirus(this);
	return flu;
}

void FluVirus::DoDie() {
	if(!this)
	delete this;
}

int FluVirus::InitResistance(int n1, int n2) {
	srand(time(NULL));
	return (rand() % (n2 + 1 - n1)) + n1;
	
}

