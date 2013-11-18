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
	
	Stack(const Stack& other)
	: 	top_(other.top_),
		capacity_(other.capacity_),
		data_(new int[capacity_])
	{
		for(int i=0;i<top_;i++) {
			data_[i]=other.data_[i];
		}
	}
	
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

	Stack& operator=(const Stack& other) {
		if(this!=&other) {
		
			delete [] data_;
			capacity_=other.capacity_;
			top_=other.top_;
			data_=new int[capacity_];
		
			for(int i=0;i<top_;i++) {
				data_[i]=other.data_[i];
			}
		
		}
		return *this;
	}


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

	for(int i=0;i<10;i++) {
		st.push(i*10);
	}

/*	
	Stack st2;
	st2=st;

	

	while( !st2.empty() ) {
		cout << "st2.pop(): " << st2.pop() << endl;
	}

	int a=5;
	a=a;


	st=st;	
	while( !st.empty() ) {
		cout << "st.pop(): " << st.pop() << endl;
	}
*/
	Stack st3=st;
	while( !st3.empty() ) {
		cout << "st3.pop(): " << st3.pop() << endl;
	}

	

	return 0;
}





