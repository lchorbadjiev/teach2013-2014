#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
struct Node {
	T data_;
	Node* left_;
	Node* right_;
	
	Node(const T& val)
	: data_(val),
	  left_(0),
	  right_(0)
	{}

};


template<typename T>
class Tree {
	Node<T>* root_;
	
	Node<T>* copy_tree(const Node<T>* src) {
		Node<T>* dst = 0;
		if(src) {
			dst = new Node<T>(src->data_);
			dst->left_ = copy_tree(src->left_);
			dst->right_ = copy_tree(src->right_);
		}
		return dst;
	}
	
	void print(const Node<T>* ptr) {
		if(ptr) {
			cout << ptr->data_ << endl;
			print(ptr->left_);
			print(ptr->right_);
		}
	}
	
	void delete_tree(Node<T>* ptr) {
		if(ptr) {
			delete_tree(ptr->left_);
			delete_tree(ptr->right_);
			delete ptr;
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
		root_->left_ = copy_tree(left.root_);
		root_->right_ = copy_tree(right.root_);
	}
	
	void print() {
		print(root_);
	}
};

/*
bool is_integer(const string& str) {
	istringstream in(str);
	int val = 0;
	in >> val;
	return in.good();
}

Tree<string> create_tree_form(istream& in) {
	Tree<string> res;
	
	string str;
	cin >> str;
	if(!cin) {
		return res;
	}
	
	if(is_integer(str)) {
		res.create3(str, Tree<string>(), Tree<string>());
	} else {
		Tree<string> t1 = create_tree_form(in);
		cin >> str;
		Tree<string> t2 = create_tree_form(in);
		res.create3(str, t1, t2);
	}
}
*/

int main() {
	Tree<int> t;
	
	cout << "t.empty()?? " << t.empty() << endl;
	
	Tree<int> t1;
	Tree<int> t2;
	t1.create3(1, Tree<int>(), Tree<int>());
	t2.create3(3, Tree<int>(), Tree<int>());
	
	t.create3(2, t1, t2);
	cout << "t.empty()?? " << t.empty() << endl;
	t.print();
	
	t.create3(2, t1, t2);

	
//	Tree<string> tf = create_tree_form(cin);
//	tf.print();
	
	return 0;
}

