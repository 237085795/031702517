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
	ifstream file1;//<文件读入>
	file1.open(argv[1]);
	while (getline(file1, line)) {
		string line_ = way.U2G(line.c_str());//UTF-8toGB2312
		word.push_back(line_);//向vector<string> word塞入line_
	}
	file1.close();//<文件读入>
	ofstream file2;//<json手动格式化输出>
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
	file2.close();//<json手动格式化输出>
	return 0;
}

