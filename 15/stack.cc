#include <iostream>
using namespace std;

class StackError {};


class Stack {
	const static int CHUNK_SIZE=2;

	int top_;
	int capacity_;
	int *data_;
	
	bool has_capacity() const {
		return top_<capacity_;
	}
	
	void resize() {
		cout << "resize() called..." << endl;
		capacity_+=CHUNK_SIZE;
		int* new_data=new int[capacity_];
		for(int i=0;i<top_;i++) {
			new_data[i]=data_[i];
		}
		delete [] data_;
		
		data_=new_data;
	}
	
public:

	Stack()
	: top_(0),
	  capacity_(CHUNK_SIZE),
	  data_(new int[capacity_])
	{}
	
	~Stack() {
		cerr << "dtor called..." << endl;
		delete [] data_;
	}
	
	bool empty() const {
		return top_==0;
	}

	void push(int val) {
		if( !has_capacity() ) {
			resize();
		}
		data_[top_++]=val;
	}

	int pop() {
		if( empty() ) {
			throw StackError();
		}
		return data_[--top_];
	}

/*	
	void deconstruct() {
		delete [] data_;
	}
*/
};


int main() {
	Stack st;
	cout << "st.empty()? " << st.empty() << endl;
	st.push(1);
	cout << "st.empty()? " << st.empty() << endl;
	for(int i=0;i<10;i++) {
		st.push(i);
	}
	
	while( !st.empty() ) {
		cout << "st.pop(): " << st.pop() << endl;
	}
	// st.pop();
	
	
	// st.deconstruct();
	return 0;
}





