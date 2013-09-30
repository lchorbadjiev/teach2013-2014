#include <iostream>
using namespace std;

class StackError {
	int error_code_;
public:
	StackError(int code) {
		error_code_=code;
	}
	int get_error_code() {
		return error_code_;
	}
};

const int STACK_SIZE=10;

class Stack {
	int data_[STACK_SIZE];
	int top_;	
public:

	Stack() {
		top_=0;
	}
	
	bool empty() {
		return top_==0;
	}
	
	bool full() {
		return top_==STACK_SIZE;
	}
	
	int pop() {
		if(empty()) {
			throw StackError(-1);
		}
		return data_[--top_];
	}
	
	void push(int val) {
		if(full()) {
			throw StackError(+1);
		}
		data_[top_++]=val;
	}
	
	
};

int main() {
	Stack st;
	try {
		st.pop();
	} catch(StackError ex) {
		cout << "Stack error..." << endl;
		cout << "error code: " << ex.get_error_code() << endl;
	}
	cout << "ala bala portokala..." << endl;

	try {
		st.push(0);
		for(int i=1;i<=10;i++) {
			st.push(i);
		}
	} catch(StackError ex) {
		cout << "Stack error again..." << endl;	
		cout << "error code: " << ex.get_error_code() <<endl;
	}
	
	return 0;
}









