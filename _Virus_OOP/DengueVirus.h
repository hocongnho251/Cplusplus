#include"MyVirus.h"
class DengueVirus:public MyVirus
{

private:
	char m_protein[3];
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(DengueVirus * dengueVirus);
	void Setm_protein(char m_protein[4]);
	char Getm_protein();
	void DoBorn() override;
	list<MyVirus*> DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};

