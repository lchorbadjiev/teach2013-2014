#include <vector>

#include <iostream>
using namespace std;

int main() {
	vector<int> v;
	
	cout << "size=" << v.size() << endl;
	cout << "cap= " << v.capacity() << endl;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	cout << "size=" << v.size() << endl;
	cout << "cap= " << v.capacity() << endl;
	
	v[1]=42;
	
	for(int i=0;i<3;i++) {
		cout << v[i] << endl;
		cout << v.at(i) << endl;
	}

	v[1042];
	//v.at(1042);


	return 0;
}

