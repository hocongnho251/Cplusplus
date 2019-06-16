#include "Patient.h"
#include<ctime>


Patient::Patient()
{
}


Patient::~Patient()
{
}

int Patient::InitResistance() {
	srand(time(NULL));
	return rand() % 8001 + 1000;
}
void Patient::DoStart() {
	m_stage = 1;
	srand((time(NULL)));
}