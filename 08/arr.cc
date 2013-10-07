#include <iostream>
using namespace std;

int main() {
	int a[10];
	
	for(int i=0;i<10;i++) {
		a[i]=10*i;
	}

	int* p=a;
	for(int* p=a;p!= a+10 ; p++) {
		cout << (*p) << endl;
	}
	
}
