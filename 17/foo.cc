#include <iostream>
using namespace std;

class Foo {
	int bar_;
public:
	Foo(int bar=0)
	: bar_(bar)
	{}
	
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

void bar1(Foo foo) {
	cout << "bar1: " << foo.get_bar() << endl;
}


Foo bar2() {
	Foo f(44);
	cout << "bar2: " << f.get_bar() << endl;
	return f;
}

int main() {
	Foo f1(42);
	Foo f2(43);
	
	f1=f2;
	cout << "f1: " << f1.get_bar() << endl;

	Foo f3=f2;
	cout << "f3: " << f3.get_bar() << endl;
	Foo f4(f2);
	cout << "f4: " << f4.get_bar() << endl;

	bar1(f1);
	
	return 0;
}


