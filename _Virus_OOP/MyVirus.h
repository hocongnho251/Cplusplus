#pragma once
class MyVirus
{
private:
	char* m_dna;
	int m_resistance;

public:
	MyVirus();
	~MyVirus();
	MyVirus(const MyVirus *myvirus);
	void Setm_dna(char *m_dna);
	char* Getm_dna();
	void Setm_resistance(int m_resistance);
	int Getm_resistance();
	void LoadADNInformation();//  Load information from file ATGX.bin
	int ReduceReistance(int medicine_resistance);// Check reistance of virus

protected:
	virtual void  DoBorn() = 0;
	virtual void  DoClone() = 0;
	virtual void  DoDie() = 0;
	virtual void  InitResistance() = 0;

};

