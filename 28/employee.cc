#include <iostream>
#include <string>
using namespace std;


class Employee {
	string name_;
	long id_;
public:
	Employee(const string& name, long id)
	: name_(name),
	  id_(id)
	{}
	
	const string& get_name() const {
		return name_;
	}

	long get_id() const {
		return id_;
	}
	
	virtual void print() {
		cout << get_id() << "; " << get_name() << endl;
	}
};

class Manager: public Employee {
	int level_;
public:
	Manager(const string& name, long id, int level)
	: Employee(name, id),
	  level_(level)
	{}

	int get_level() const {
		return level_;
	}
	
	void print() {
		//cout << get_id() << "; " << get_name() << "; " << get_level() << endl;
		Employee::print();
		cout << "level: " << get_level() << endl;
	}
	
};


int main() {
	Employee e1("Pesho Peshev", 1001L);
	Employee e2("Ivan Ivanov", 2002L);
	Manager m1("Gosho Goshev" ,10001L, 5);

	cout << m1.get_name() << "; " << m1.get_id() << "; " << endl;
	e1.print();
	e2.print();
	m1.print();
	
	Employee& re1 = e1;
	Employee& re2 = m1;
	
	// Manager& rm1 = e1;
	
	re1.print();
	re2.print();
	
	return 0;
}





