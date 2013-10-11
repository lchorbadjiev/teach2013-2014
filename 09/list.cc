#include <list>
#include <iostream>
using namespace std;

void print_all(list<int>& l) {
	for(list<int>::iterator it=l.begin();
		it!=l.end();++it) {
	
		cout << (*it) << ' ';	
	}	
	cout << endl;
}



int main() {
	list<int> l1;
	cout << "l1.empty(): " << l1.empty() << endl;

	l1.push_back(1);
	l1.push_back(2);
	
	l1.push_front(-1);
	l1.push_front(-2);
	print_all(l1);

	list<int> l2(10,-3);
	print_all(l2);
	
	list<int> l3(l1.begin(),l1.end());
	print_all(l3);
	
	int a[]={0,1,2,3,4,5,6,7,8,9};
	list<int> l4(a,a+10);
	print_all(l4);
	
	l4.insert(l4.begin(),-1);
	l4.insert(l4.end(),10);
	print_all(l4);
	
	l4.erase(l4.begin());
	print_all(l4);
	l4.erase(l4.begin(),l4.end());
	print_all(l4);
	

	return 0;
}










