#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {
	string s1="Hello world 42";
	istringstream in1(s1);
	
	double val;
	string token;
	in1 >> token;
	cout << token << endl;
	
	in1 >> token;
	cout << token << endl;
	
	in1 >> val;
	cout << val << endl;


	ostringstream out1;
	out1 << token << ' ' << val;
	cout << "out1: " << out1.str() << endl;
	
	out1 << "ala bala portokala";
	cout << "out1: " << out1.str() << endl;

	return 0;
}
