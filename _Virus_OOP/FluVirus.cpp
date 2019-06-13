#include "FluVirus.h"
#include <cstdlib>
#include <ctime>



FluVirus::FluVirus()
{
}


FluVirus::~FluVirus()
{
}

void FluVirus::Setm_color(int m_color) {
	m_color = rand()%2;
	if (m_color == 0) {
		m_color = 0x0000ff;
	}
	else {
		m_color = 0xff0000;
	}
	this->m_color = m_color;
}

int FluVirus::Getm_color() {
	return this->m_color;
}