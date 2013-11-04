

class Foo {
	int a_;
public:
	Foo(int a) {
		a_=a;
	}
	
	int get_a() {
		return a_;
	}

	void set_a(int a) {
		a_=a;
	}

};

class Bar {
	Foo foo_;
public:
	Bar()
	:foo_(42)
	{
	
	}

};


int main() {

	return 0;
}

