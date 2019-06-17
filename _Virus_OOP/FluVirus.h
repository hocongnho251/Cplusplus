#include "MyVirus.h"
#include<list>

using namespace std;
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
	list<MyVirus*> DoClone() override;
	void DoDie() override; 
	void InitResistance() override;


};

