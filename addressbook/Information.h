#pragma once
#include<string>

using namespace std;

class Information
{
public:
	Information();
	~Information();
	string s;//��Ϣ��
	string name;
	string phone;
	string province;//ʡ
	string city;//��
	string county;//��
	string town;//��
	string detailedaddress;//��ϸ��ַ
	string level;
	//void Input();
	void Output();
	void GetLevel();
	void GetName();
	void GetPhone();
	void FiveDivision();
	void Solution();
};

