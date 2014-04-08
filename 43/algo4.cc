#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

void print_fn(int v) {
	cout << v << ' ';
}

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	list<int> l(a, a+10);
	for_each(l.begin(), l.end(), print_fn);
	cout << endl;
	
	list<int>::iterator it = find(l.begin(), l.end(), 7);
	if(it!=l.end()) {
		cout << "element found..." << endl;
		cout << "val=" << *it << endl;
		l.insert(it, -7);
		for_each(l.begin(), l.end(), print_fn);
		cout << endl;
	} else {
		cout << "element NOT found..." << endl;
	}
	return 0;
}

