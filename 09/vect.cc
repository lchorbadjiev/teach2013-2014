#include <iostream>
#include <vector>

using namespace std;

void print_all(vector<int>& v) {
	for(vector<int>::iterator it=v.begin();
		it!=v.end();++it) {
		
		cout << (*it) << ' ';
	}
	cout << endl;
}



int main() {
	
	vector<int> v1(10,-3);
	print_all(v1);


	vector<int> v2(v1.begin(),v1.end());
	print_all(v2);
	
	int a[]={0,1,2,3,4,5,6,7,8,9};
	vector<int> v3(a,a+10);
	print_all(v3);
	
	
	v3.insert(v3.begin(),-1);
	v3.insert(v3.end(),10);
	print_all(v3);
	
	v3.erase(v3.begin());
	print_all(v3);
	v3.erase(v3.begin(),v3.end());
	print_all(v3);
	
	
	return 0;
}












