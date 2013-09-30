#include <iostream>
using namespace std;


class StackError {};

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
			throw StackError();
		}
		return data_[--top_];
	}
	
	void push(int val) {
		if(full()) {
			throw StackError();
		}
		data_[top_++]=val;
	}
	
};

int main() {
	Stack st;
	
	try {
		st.pop();
		cout << "ala bala portokala" << endl;
	} catch(StackError ex) {
		cout << "stack error on pop..." << endl;
	}
	cout << "... continue ... " << endl;
	
	try {
		for(int i=0;i<=10;i++) {
			st.push(i);
		}
	} catch(StackError ex) {
		cout << "stack error on push..." << endl;	
	}
	cout << "... continue ... " << endl;

	return 0;
}












