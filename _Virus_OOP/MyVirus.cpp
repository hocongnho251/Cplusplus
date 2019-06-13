#include "MyVirus.h"
#include <iostream>
#include<fstream>
#include<string>
#include<string.h>

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
	string temp;
	if (fileInPut.is_open()) {
		getline(fileInPut, temp, ' ');

		char *c = new char[temp.size() + 1];
		for (int i = 0; i < temp.size(); i++){
			c[i] = temp[i];
		}
		c[temp.size()] = '\0';
		this->Setm_dna(c);
		cout << m_dna;

		
	
	}
	else {
		cout << "Open file ERRO"<< endl;
	}
	
}

