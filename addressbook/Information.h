#pragma once
#include<string>

using namespace std;

class Information
{
public:
	Information();
	~Information();
	string s;//信息串
	string name;
	string phone;
	string province;//省
	string city;//市
	string county;//县
	string town;//镇
	string detailedaddress;//详细地址
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

