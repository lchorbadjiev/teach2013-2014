#include <stdlib.h>

struct Bar {
	int foo;
	int b;
};



int main() {


	Bar b;
	
	Bar* ptr=(Bar*) malloc(sizeof(struct Bar));
	
	ptr->foo=5;
	ptr->b=6;
	
	free(ptr);
	
	return 0;
}

