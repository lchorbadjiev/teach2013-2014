#include <vector>
#include <iostream>
using namespace std;


int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	for(int i=0;i<v.size();i++) {
		cout << v[i] << endl;
	}


	for(vector<int>::iterator it=v.begin();
		it!=v.end();++it) {
	
		cout << (*it) << endl;	
	}

	return 0;	
}
