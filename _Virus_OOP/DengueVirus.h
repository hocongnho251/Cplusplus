#include"MyVirus.h"
#include"MyVirus.h"
class DengueVirus:public MyVirus
{

private:
	char m_protein[3] = {'NS5','NS3','E'};
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(DengueVirus * dengueVirus);
	void Setm_protein(char m_protein[4]);
	char Getm_protein();
	void DoBorn() override;
	DengueVirus* DoClone() override;
	void DoDie() override;
	int InitResistance(int n1, int n2) override;
};

