#include <string>
#include <iostream>
using namespace std;

#include <stdio.h>

int main() {

	string s1="Hello";
	string s2=" ";
	string s3="World!";
	
	string msg=s1+s2+s3;
	cout << msg << endl;

	cout << "size: " << msg.size() << "; " << msg.length() << endl;

	for(int i=0;i<msg.size();++i) {
		cout << msg[i] << "; " << msg.at(i) << endl;
	}

	
	string dirname="/home/lubo";
	string filename="aaa.txt";
	string fullname=dirname+"/"+filename;
	cout << fullname << endl;	
	
	FILE* f=fopen(fullname.c_str(),"r+");

	return 0;
}















