#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T data_;
	Node* left_;
	Node* right_;
	
	Node(T val)
	: data_(val),
	  left_(0),
	  right_(0)
	{}
	
};

template<typename T>
class Tree {

	Node<T>* root_;
	
	void delete_tree(Node<T>* ptr) {
		if (ptr) {
			delete_tree(ptr->left_);
			delete_tree(ptr->right_);
			delete ptr;
		}
	}
	
	Node<T>* copy_tree(const Node<T>* src) {
		Node<T>* dst=0;
		if(src) {
			dst = new Node<T>(src->data_);
			dst->left_ = copy_tree(src->left_);
			dst->right_ = copy_tree(src->right_);
		}
		return dst;
	}
	
	
	void print(Node<T>* ptr) {
		if(ptr) {
			cout << ptr->data_ << endl;
			print(ptr->left_);
			print(ptr->right_);
		}
	}
	
public:
	Tree()
	: root_(0)
	{}
	
	~Tree() {
		delete_tree(root_);
	}
	
	bool empty() const {
		return root_ == 0;
	}
	
	
	void create3(const T& val,
				const Tree<T>& left,
				const Tree<T>& right) {
		
		delete_tree(root_);
		root_ = new Node<T>(val);
		root_->left_=copy_tree(left.root_);
		root_->right_=copy_tree(right.root_);
	}
	
	void print() {
		print(root_);
	}
};

int main() {
	Tree<int> t, t1, t2, t3;
	cout << "t.empty()? " << t.empty() << endl;
	
	t.create3(3,Tree<int>(), Tree<int>());
	cout << "t.empty()? " << t.empty() << endl;
	
	t1.create3(2, Tree<int>(), Tree<int>());

	t2.create3(1, t, t1);


	t2.print();
	
	return 0;
}

