#include "FluVirus.h"
#include <cstdlib>
#include <ctime>
#include<iostream>
#include"Patient.h"

using namespace std;



FluVirus::FluVirus()
{
	this->DoBorn();
	this->InitResistance();

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
	//srand(time(NULL));
	m_color = rand() % 2;
	if (m_color == 0) {
		
		this->m_color=0xff0000;//red virus
	}
	else {
		
		this->m_color=0x0000ff;//blu virus
	}
	
}

list<MyVirus*> FluVirus::DoClone() {
	FluVirus * flu = new FluVirus();
	list<MyVirus*> listFlu;
	listFlu.push_back(flu);
	return listFlu;
	

}

void FluVirus::DoDie() {
	if(!this)
	delete this;
}

void FluVirus::InitResistance() {
	//srand(time(NULL));
	if (this->m_color == 0xff0000) {
		this->m_resistance=rand() % (20 -10 +1) + 10;
		cout << "Resistance of RED:" << this->m_resistance << endl;
	}else {
		this->m_resistance=rand() % (15 + 1 - 10) + 10;
		cout << "Resistance of BLU:" << this->m_resistance << endl;
	}
	
}

