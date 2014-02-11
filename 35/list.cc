#include <iostream>
using namespace std;

class ListError{};

template<typename T>
class List {

	struct Elem {
		T data_;
		Elem* next_;
		
		Elem(T val)
		: data_(val),
		  next_(0)
		{}
	};
	
	Elem* head_;

public:
	List()
	: head_(0)
	{}
	
	bool empty() const {
		return head_==0;
	}
	
	void push_front(T val) {
		Elem* new_elem=new Elem(val);
		
		new_elem->next_=head_;
		head_=new_elem;
	}
	
	T front() const {
		if(empty()) {
			throw ListError();
		}
		return head_->data_;
	}
	
	void pop_front() {
		if(empty()) {
			throw ListError();
		}
		Elem* old_head=head_;
		head_=head_->next_;
		delete old_head;
	}
};

template<typename T>
class Stack: protected List<T> {

public:
	void push(T val) {
		List<T>::push_front(val);
	}
	
	T pop() {
		T res=List<T>::front();
		List<T>::pop_front();

		return res;
	}
};

int main() {
	List<int> l1;
	
	cout << l1.empty() << endl;
	l1.push_front(42);
	cout << l1.empty() << endl;
	cout << l1.front() << endl;
	l1.pop_front();
	cout << l1.empty() << endl;
	
	List<double> l2;
	for(int i=0;i<10;++i) {
		l2.push_front(i*3.14);
	}
	while(!l2.empty()) {
		cout << l2.front() << ' ';
		l2.pop_front();
	}
	cout << endl;
	
	
	Stack<int> st1;
	//cout << st1.empty() << endl;
	for(int i=0;i<10;++i) {
		st1.push(i*10);
		//st1.push_front(i*20);
	}
	
	for(int i=0;i<10;++i) {
		cout << st1.pop() << ' ';
		//cout << st1.front() << ' ';
		//st1.pop_front();
	}
	cout << endl;
	
	return 0;
}

