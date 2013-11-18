#include <iostream>
using namespace std;


class Foo {
	int bar_;
public:
	Foo(int bar)
	: bar_(bar)
	{
		cout << "c'tor called..." << endl;
	}
	
	Foo(const Foo& other)
	: bar_(other.bar_)
	{
		cout << "copy c'tor called..." << endl;
	}
	
	int get_bar() const {
		return bar_;
	}
	
	
	Foo& operator=(const Foo& other) {
		cout << "op=() called..." << endl;
		bar_=other.bar_;
		return *this;
	}
};

void bar1(Foo f) {
	cout << "bar1: " << f.get_bar() << endl;
}

int main() {
	Foo f1(42);
	Foo f2(43);
	
	f2=f1;
	cout << "f2: " << f2.get_bar() << endl;

	Foo f3=f1;
	cout << "f3: " << f3.get_bar() << endl;
	Foo f4(f1);
	cout << "f4: " << f4.get_bar() << endl;

	bar1(f4);

	return 0;
}





