#include "pch.h"
#include"information.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<Windows.h>
#include"Transcode.h"


using namespace std;
int main()
{	
	Transcode way;
	Information ifo[100];
	string line;
	vector<string> word;
	ifstream file1;
	file1.open("1.txt");
	while (getline(file1, line)) {
		word.push_back(line);//œÚvector<string> word»˚»Îline	
	}
	file1.close();
	ofstream file2;
	file2.open("2.txt", ios::app);
	file2 << way.G2U("[");
	file2.close();
	for (int i = 0; i < word.size(); i++) {
		ifo[i].s = word[i];
		ifo[i].Solution();
		if (i != word.size()-1) {
			ofstream file2;
			file2.open("2.txt", ios::app);
			file2 << way.G2U(",");
			file2.close();
		}
			
	}
	file2.open("2.txt", ios::app);
	file2 << way.G2U("]")<<endl;
	file2.close();
	return 0;
}

