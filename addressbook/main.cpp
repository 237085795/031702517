#include "pch.h"
#include"information.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<Windows.h>
#include"Transcode.h"


using namespace std;
int main(int argc,char *argv[])
{	
	Transcode way;
	Information ifo[2000];
	string line;
	vector<string> word;
	ifstream file1;//<�ļ�����>
	file1.open(argv[1]);
	while (getline(file1, line)) {
		string line_ = way.U2G(line.c_str());//UTF-8toGB2312
		word.push_back(line_);//��vector<string> word����line_
	}
	file1.close();//<�ļ�����>
	ofstream file2;//<json�ֶ���ʽ�����>
	file2.open(argv[2], ios::app);
	file2 << way.G2U("[");
	file2.close();
	for (int i = 0; i < word.size(); i++) {
		ifo[i].s = word[i];
		ifo[i].Solution(argv[2]);
		if (i != word.size()-1) {
			ofstream file2;
			file2.open(argv[2], ios::app);
			file2 << way.G2U(",");
			file2.close();
		}
			
	}
	file2.open(argv[2], ios::app);
	file2 << way.G2U("]")<<endl;
	file2.close();//<json�ֶ���ʽ�����>
	return 0;
}

