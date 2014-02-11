#include <iostream>
#include <string>
using namespace std;

class StackError{};

template<typename T>
class Stack {
	const static int SIZE = 10;
	
	T data_[SIZE];
	int top_;
public:
	Stack()
	: top_(0)
	{}

	bool empty() const { 
		return top_==0;
	}
	bool full() const {
		return top_==SIZE;
	}
	
	void push(T val) {
		if(full()) {
			throw StackError();
		}
		data_[top_++] = val;
	}
	
	T pop() {
		if(empty()) {
			throw StackError();
		}
		return data_[--top_];
	}
};


int main() {
	Stack<int> st1;
	cout << st1.empty() << endl;
	cout << st1.full() << endl;
	for(int i=0;i<10;i++) {
		st1.push(i);
	}
	cout << st1.empty() << endl;
	cout << st1.full() << endl;
	// st1.push(42);
	while(!st1.empty()) {
		cout << st1.pop() << endl;
	}
	
	Stack<double> st2;
	for(int i=0;i<10;++i) {
		st2.push(i*3.14);
	}
	while(!st2.empty()) {
		cout << st2.pop() << endl;
	}
	
	Stack<string> st3;
	for(int i=0;i<10;i++) {
		st3.push("hello");
	}
	while(!st3.empty()) {
		cout << st3.pop() << endl;
	}
	
	return 0;
}
