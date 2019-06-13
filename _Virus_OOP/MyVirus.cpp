#include "MyVirus.h"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;



MyVirus::MyVirus()
{
}


MyVirus::~MyVirus()
{
}

void MyVirus::Setm_dna(char* m_dna){
	this->m_dna = m_dna;

}

char* MyVirus::Getm_dna() {
	return this->m_dna;
}

void MyVirus::Setm_resistance(int m_resistance) {
	this->m_resistance = m_resistance;
}

int MyVirus::Getm_resistance() {
	return this->m_resistance;
}

void MyVirus::LoadADNInformation() {
	ifstream fileInPut("ATGX.bin");
	if (fileInPut.is_open()) {
		fileInPut >> m_dna;
	}
	
}

