#include "MyVirus.h"
class FluVirus:public MyVirus
{
private:
	int m_color;

public:
	FluVirus();
	~FluVirus();
	FluVirus(FluVirus* fluVirus);
	void Setm_color(int m_color);
	int Getm_color();
	void DoBorn() override;
	FluVirus* DoClone() override;
	void DoDie() override; 
	int InitResistance(int a, int b) override;


};

