#include <string>
#include <iostream>

using namespace std;
#include <stdio.h>

int main() {
	string s1="Hello";
	
	s1+=" ";
	s1+="World!";
	cout << s1 << endl;

	cout << "s1.size(): " << s1.size() 
		<< "; s1.length(): " << s1.length() 
		<< endl;

	for (int i=0;i<s1.size(); i++) {
		cout << s1[i] << "; " << s1.at(i) << endl;
	}

	const char* s=s1.c_str();
	cout << "s: " << s << endl;

	string dirname="/home/lubo/";
	string filename="aaa.txt";
	
	string fullname=dirname+filename;
	
	FILE* f=fopen(fullname.c_str(),"r");

	return 0;
}

