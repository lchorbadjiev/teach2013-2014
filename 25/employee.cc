#include <iostream>
#include <string>

using namespace std;

class Employee {
//protected:
	long id_;
	string name_;
public:
	Employee(long id, string name)
	: id_(id), name_(name)
	{}
	
	long get_id() const {
		return id_;
	}
	
	const string& get_name() const {
		return name_;
	}

	virtual void print() {
		cout << "id: " << get_id() << "; name: " << get_name() << endl;
	}

};


class Manager: public Employee {
	int level_;
public:
	Manager(long id, string name, int level)
	: Employee(id, name),
	  level_(level)
	{}
	
	int get_level() const {
		return level_;
	}
	
	virtual void print() {
		Employee::print();
		cout << "level: " << get_level() << endl;
/*	
		cout << "id: " << get_id() << "; name: " << get_name() 
			<< "; l: " << get_level() << endl;
*/
	}
};


int main() {
	Employee e1(1L,"Pesho Peshev");
	Employee e2(2L, "Ivan Ivanov");
	
	Manager m1(3L, "Gosho Goshev", 3);

	//e1.id_;
	
	e1.print();
	e2.print();
	m1.print();

/*
	cout << "e1: " << e1.get_id() << "; " << e1.get_name() << endl;
	cout << "e2: " << e2.get_id() << "; " << e2.get_name() << endl;

	cout << "m1: " << m1.get_id() << "; " << m1.get_name() << "; "
		<< m1.get_level() << endl;
*/


	Employee& re1 = e1;
	Employee& re2 = m1;
	re1.print();
	re2.print();
	
	Manager& rm1 = m1;
	// Manager& rm2 = e1;
	
	
	return 0;
}







