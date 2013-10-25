


class Foo {
	int a_;
public:
	Foo(int a) {
		a_=a;
	}

	void set_a(int a) {
		a_=a;
	}

	int get_a() {
		return a_;
	}
};


class Bar {
	Foo foo_;
public:
	Bar()
	: foo_(5)
	{
	
	}

};




int main() {
	Bar b;
	
	return 0;
}

