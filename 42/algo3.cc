#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

void print_fn(int val) {
	cout << val << ' ';
}

int main() {
	int a[]={1,2,3,4,5,6,7,8,9,0};
	list<int> l(a, a+10);
	
	list<int> l1(l.size());
	list<int> l2;
	
	
	cout << "l.size()=" << l.size() << endl;
	cout << "l1.size()=" << l1.size() << endl;
	cout << "l2.size()=" << l2.size() << endl;
	
	copy(l.begin(),l.end(), l1.begin());
	for_each(l1.begin(), l1.end(), print_fn);
	cout << endl;

	copy(l.begin(),l.end(), l2.begin());
	for_each(l2.begin(), l2.end(), print_fn);
	cout << endl;

	
	back_insert_iterator<list<int> > bit = 
		back_inserter(l2);
	*bit++=0;
	*bit++=1;
	*bit++=2;
	for_each(l2.begin(), l2.end(), print_fn);
	cout << endl;

	front_insert_iterator<list<int> > fit =
		front_inserter(l2);
	*fit++=-1;
	*fit++=-2;
	*fit++=-3;
	for_each(l2.begin(), l2.end(), print_fn);
	cout << endl;
	
	list<int> l3;
	bit=back_inserter(l3);
	copy(l.begin(), l.end(), bit);
	for_each(l3.begin(), l3.end(), print_fn);
	cout << endl;
	fit=front_inserter(l3);
	copy(l.begin(), l.end(), fit);
	for_each(l3.begin(), l3.end(), print_fn);
	cout << endl;

	copy(l3.begin(), l3.end(), 
		ostream_iterator<int>(cout,"\n"));
	copy(l.begin(), l.end(),
		ostream_iterator<int>(cout,", "));
	cout << endl;
	
	return 0;
}


