#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;


class print_fn {
public:
	void operator()(int val) {
		cout << val << ' ';
	}
};

void print (int val) {
	cout << val << ", ";
}

int main() {

	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v(a, a+10);
	list<int> l(a, a+10);
	

	print_fn pf;
	pf(5);
	pf(6);
	cout << endl;
	
	for_each(v.begin(), v.end(), print_fn());
	cout << endl;
	for_each(l.begin(), l.end(), print);
	cout << endl;
	for_each(a, a+10, pf);
	cout << endl;
	
	return 0;
}


