#include "pch.h"
#include "Information.h"
#include<iostream>
#include<regex>
#include<string>
#include<fstream>

using namespace std;

Information::Information()
{
}

Information::~Information()
{
}

//void Information::Input()
//{
//	cin >> s;
//}

void Information::Output()
{
	ofstream file2;
	file2.open("2.txt",ios::app);
	file2<< "{\"����\":\"" << name << "\",\"�ֻ�\":\""<< phone  << "\",\"��ַ\":[\"" << province << "\",\"" << city << "\",\"" << county<<"\",\"" << town <<"\",\"" << detailedaddress << "\"]}";
	file2.close();
}

void Information::GetLevel()
{
	level = s[0];
	string s_ = s.substr(2);
	s = s_;
}

void Information::GetName()
{
	int i_;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			i_ = i;
			break;
		}
	}//��־������ַ�ֽ��
	string name_(s, 0, i_++);//����
	string s_(s, i_);//��ַ
	name=name_;
	s = s_;
}

void Information::GetPhone()
{
	regex exp("\\d{11}");
	smatch sm;
	regex_search(s, sm, exp);//��ȡ�绰����
	phone = sm[0];
	string pres = sm.prefix();
	string sufs = sm.suffix();
	s = pres + sufs;//ʣ�ಿ�ֺϲ�
}

void Information::FiveDivision()
{
	s.pop_back();
	regex exp("([^ʡ]+������|.*?ʡ|.*?������)?([^��]+������|.*?����|.*?������λ|.+��|��Ͻ��|.*?��|.*?��)?([^��]+��|.+?��|.+��|.+��|.+����|.+��)?([^��]+��|.+��|.+�ֵ�)?(.*)");
	smatch sm;
	regex_search(s, sm, exp);
	province = sm[1];
	city = sm[2];
	county = sm[3];
	town = sm[4];
	detailedaddress = sm[5];
}

void Information::Solution()
{
	GetLevel();
	GetName();
	GetPhone();
	if(level=="1")
		FiveDivision();
	if(level=="2")
		FiveDivision();
	if(level=="3")
		FiveDivision();
	Output();
}
