#include <vector>
#include <iostream>
using namespace std;

void print_all(vector<int>& v) {

	cout << "size: " << v.size() << endl;
	
	for(vector<int>::iterator it=v.begin();
		it!=v.end();++it) {
		
		cout << (*it) << ' ';
	}
	cout << endl;
}


int main() {
	vector<int> v1;
	print_all(v1);
	
	v1.push_back(1);
	v1.push_back(2);
	print_all(v1);
	
	vector<int> v2(10,-3);
	print_all(v2);
	
	vector<int> v3(v1.begin(),v1.end());
	print_all(v3);
	
	
	int a[]={0,1,2,3,4,5,6,7,8,9};
	vector<int> v4(a,a+10);
	print_all(v4);


	vector<int> v5(v4.begin(),v4.begin()+5);
	print_all(v5);
	
	
	v4.insert(v4.begin(),-1);
	v4.insert(v4.end(),10);
	print_all(v4);
	
	
	v4.erase(v4.begin());
	print_all(v4);
	
	v4.erase(v4.begin(),v4.end());
	print_all(v4);
	
	return 0;
}











