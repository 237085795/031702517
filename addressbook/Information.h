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
	string da1;
	string da2;
	string da3;
	string level;
	//void Input();
	void Output(string outfilename);
	void GetLevel();
	void GetName();
	void GetPhone();
	void FiveDivision();
	void SevenDivision();
	void Solution(string outfilename);
};

