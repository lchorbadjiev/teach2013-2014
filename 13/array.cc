#include <iostream>
#include <exception>

using namespace std;


class Array {
	const unsigned int size_;
	int *data_;
public:
	Array(unsigned size)
	: size_(size)
	  
	{
		data_ = new int[size_];
	}
	
	
	int& operator[](int index) {
		if(index>=0 && index<size_) {
			return data_[index];
		}
		throw exception();
	}

};


int main() {
	Array a(10);
	
	//int b=a[11];
	for(int i=0;i<10;i++) {
		a[i]=i;
	}

	for(int i=0;i<10;i++) {
	
		cout<< a[i] << endl;
	}


	//5=a[1];
	
	return 0;
}

