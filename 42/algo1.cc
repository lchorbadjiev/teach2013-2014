#include <algorithm>
#include <iostream>
#include <list>
using namespace std;


class sum {
	int value_;
public:
	sum()
	: value_(0)
	{}
	
	int value() const {
		return value_;
	}
	
	void operator()(int val) {
		value_+=val;
	}
};


class mul {
	int value_;
public:
	mul()
	: value_(1)
	{}
	
	int value() const {
		return value_;
	}
	
	void operator()(int val) {
		value_*=val;
	}};

void print_fn(int val) {
	cout << val << ' ';
}

int main() {
	int a[] = {10,1,2,3,4,5,6,7,8,9};
	list<int> l(a, a+10);
	
	sum s = for_each(l.begin(), l.end(), sum());
	cout << s.value() << endl;
	
	mul m = for_each(l.begin(), l.end(), mul());
	cout << m.value() << endl;
	
	list<int>::iterator it=find(l.begin(), l.end(), 7);
	if(it!=l.end()) {
		cout << "element found..." << endl;
		cout << "val=" << *it << endl;
		l.insert(it, -7);
		for_each(l.begin(), l.end(), print_fn);
		cout << endl;
	} else {
		cout << "element not found..." << endl;
	}
	
	return 0;
}

