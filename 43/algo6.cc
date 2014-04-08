#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <fstream>
using namespace std;

void print_fn(int v) {
	cout << v << ' ';
}

int main() {
	int a[]={0,1,2,3,4,5,6,7,8,9};
	list<int> l(a, a+10);
	
	list<int> l1(10);
	
	copy(l.begin(), l.end(), l1.begin());
	
	for_each(l1.begin(), l1.end(), print_fn);
	cout << endl;


	list<int> l2;
	back_insert_iterator<list<int> > bit(l2);
	
	*bit++=0;
	*bit++=1;
	*bit++=2;	
	for_each(l2.begin(), l2.end(), print_fn);
	cout << endl;

	front_insert_iterator<list<int> > fit(l2);
	*fit++=-1;
	*fit++=-2;
	*fit++=-3;
	for_each(l2.begin(), l2.end(), print_fn);
	cout << endl;
	
	list<int> l3;
	copy(l.begin(), l.end(), back_inserter(l3));
	for_each(l3.begin(), l3.end(), print_fn);
	cout << endl;

	copy(l.begin(), l.end(), front_inserter(l3));
	for_each(l3.begin(), l3.end(), print_fn);
	cout << endl;
	
	ostream_iterator<int> oit(cout,", ");
	*oit++=10;
	*oit++=11;
	*oit++=12;
	cout << endl;
	
	
	copy(l3.begin(), l3.end(),
		ostream_iterator<int>(cout, "\n"));

	ofstream f("hello.txt");
	copy(l3.begin(), l3.end(),
		ostream_iterator<int>(f,"\n"));
	

	return 0;
}
