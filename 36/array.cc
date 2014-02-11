#include <iostream>
using namespace std;

class ArrayError {};

template<typename T>
class Array {
	int size_;
	T* data_;
public:
	Array(int size)
	: size_(size),
	  data_(new T[size_])
	{}
	
	~Array() {
		delete [] data_;
	}
	
	int size() const {
		return size_;
	}
	
	T& operator[](int index) {
		if(index<0 || index>= size_) {
			throw ArrayError();
		}
		return data_[index];
	}

};

int main() {
	Array<int> a1(10);
	for(int i=0;i<a1.size();++i) {
		a1[i]=i*15;
	}
	for(int i=0;i<a1.size();++i) {
		cout << a1[i] << ' ';
	}
	cout << endl;
	
	return 0;
}

