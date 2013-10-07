#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	for(int i=0;i<10;i++) {
		v.push_back(i);
	}
	cout << "v.size()=" << v.size() << endl;

	int sum=0;
	for(vector<int>::iterator it=v.begin();
		it!=v.end();++it) {
		sum+=*it;
		cout << (*it) << endl;	
	}
	cout << "sum=" << sum << endl;
	
	
	return 0;
}


