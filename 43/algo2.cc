#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

class print_obj {
	ostream& out_;
public:
	print_obj(ostream& out)
	: out_(out)
	{}
	
	void operator()(int val) {
		out_ << val << ' ';
	}

};

void print_fun(int val) {
	cout << val << ", ";
}


int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v(a, a+10);
	list<int> l(a, a+10);

	print_obj po1(cout);
	print_obj po2(cerr);
	
	po1(42);
	cout << endl;
	po2(43);
	cerr << endl;

	for_each(v.begin(), v.end(), po1);
	cout << endl;
	for_each(l.begin(), l.end(), print_fun);
	cout << endl;	
	for_each(a, a+10, po2);
	cerr << endl;
	
	return 0;
}

