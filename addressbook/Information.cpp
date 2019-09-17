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
	file2<< "{\"姓名\":\"" << name << "\",\"手机\":\""<< phone  << "\",\"地址\":[\"" << province << "\",\"" << city << "\",\"" << county<<"\",\"" << town <<"\",\"" << detailedaddress << "\"]}";
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
	}//标志姓名地址分界点
	string name_(s, 0, i_++);//姓名
	string s_(s, i_);//地址
	name=name_;
	s = s_;
}

void Information::GetPhone()
{
	regex exp("\\d{11}");
	smatch sm;
	regex_search(s, sm, exp);//提取电话号码
	phone = sm[0];
	string pres = sm.prefix();
	string sufs = sm.suffix();
	s = pres + sufs;//剩余部分合并
}

void Information::FiveDivision()
{
	s.pop_back();
	regex exp("([^省]+自治区|.*?省|.*?行政区)?([^市]+自治州|.*?地区|.*?行政单位|.+盟|市辖区|.*?市|.*?县)?([^县]+县|.+?区|.+市|.+旗|.+海域|.+岛)?([^区]+区|.+镇|.+街道)?(.*)");
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
