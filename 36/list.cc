#include <iostream>
using namespace std;

class ListError{};

template<typename T>
class List {
	struct Elem {
		T data_;
		Elem* next_;
		
		Elem(T val) : data_(val), next_(0)
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
		Elem* new_elem = new Elem(val);
		new_elem->next_ = head_;
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
	
	~List() {
		while(!empty()) {
			pop_front();
		}
	}
};


int main() {
	List<int> l1;
	cout << l1.empty() << endl;
	l1.push_front(42);
	cout << l1.empty() << endl;
	cout << l1.front() << endl;
	l1.push_front(43);
	cout << l1.front() << endl;
	l1.pop_front();
	cout << l1.front() << endl;	
	return 0;
}

