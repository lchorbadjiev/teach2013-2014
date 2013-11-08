#include <cstdlib>
#include <iostream>
using namespace std;

class Foo {
	int bar_;
public:
	Foo()
	: bar_(0)
	{}
	
	Foo(int bar)
	: bar_(bar)
	{}
	
	int get_bar() const {
		return bar_;
	}
};


int main() {
	Foo* pf=(Foo*)  malloc(sizeof(Foo));

	pf->get_bar();//????

	free(pf);
	
	
	Foo* pf1= new Foo;
	Foo* pf2= new Foo(42);
	Foo* pf3= new Foo[42];
	
	
	cout << "pf1: " << pf1->get_bar() << endl;
	cout << "pf2: " << pf2->get_bar() << endl;

	cout << "pf3: ";
	for(int i=0;i<42;i++) {
		cout << pf3[i].get_bar() << " ";
	}
	cout << endl;
	
	delete pf1;
	delete pf2;
	delete [] pf3;
	
	return 0;
}











