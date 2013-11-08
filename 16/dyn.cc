#include <cstdlib>
#include <iostream>
using namespace std;


int main() {
	int i;
	int* pi=&i;
	
	int* p;
	p=(int*)malloc(1000*sizeof(int));

	i=41;
	p[0]=42;
	p[1]=43;
	//...
	
	cout << "i=" << i << endl;
	cout << "*p=" << *p << endl;

	free(p);

	return 0;
}




