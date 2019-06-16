#pragma once
#include "MyVirus.h"
class Patient
{

public:
	int m_resistance;
	list<MyVirus*> m_virusList;
	int m_stage ;
public:
	Patient();
	~Patient();
	int InitResistance();
	void DoStart();
	void TakeMedicine();
	void DoDie();
};

