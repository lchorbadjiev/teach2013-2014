#include <vector>
#include <iostream>

using namespace std;


int main() {
	vector<int> v;
	
	cout << "size: " << v.size() << endl;
	cout << "empty:" << v.empty() << endl;
	cout << "cap:  " << v.capacity() << endl;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	cout << "size: " << v.size() << endl;
	cout << "empty:" << v.empty() << endl;
	cout << "cap:  " << v.capacity() << endl;

	v[1]=42;
	v.at(2)=43;
	
	for(int i=0;i<v.size();i++) {
		cout << "v[" << i << "]=" << v[i] << "; " << v.at(i) << endl;
	}
	
	v.at(5);
	//v[42];

	return 0;
}














