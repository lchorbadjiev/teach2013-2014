#include <iostream>
using namespace std;

class ArrayError {};

template<typename T>
class Array {
	T* data_;
	int size_;
	
public:
	Array(int size)
	: data_(new T[size]),
	  size_(size)
	{}
	
	~Array() {
		delete [] data_;
	}
	
	int size() const {
		return size_;
	}
	
	T& at(int index) {
		if(index>=size_ || index < 0) {
			throw ArrayError();
		}
		
		return data_[index];
	}
	
	T& operator[](int index) {
		return at(index);
	}
};


int main() {
	Array<int> a1(10);
	for(int i=0;i<a1.size();++i) {
		a1.at(i) = i;
	}
	
	for(int i=0;i<a1.size();++i) {
		cout << a1.at(i) << endl;
	}
	
	Array<double> a2(10);
	for(int i=0;i<a2.size();++i) {
		a2[i]=i*3.14;
	}
	
	for(int i=0;i<a2.size();++i) {
		cout << a2[i] << ' ';
	}
	cout << endl;
	
	return 0;
}


