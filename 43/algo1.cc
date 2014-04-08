#include <iostream>


using namespace std;

class print_fn {

public:
	void operator()(int val) {
		cout << "ala bala " << val <<endl;
	}

};

int main() {
	print_fn pf;
	
	pf(42);
	
	return 0;
}

