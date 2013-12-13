#include <iostream>
#include <string>
using namespace std;


class Employee{
	long id_;
	string name_;
public:
	Employee(long id, string name)
	: id_(id),name_(name)
//	: id_(id),name_(name_) // Check the difference...
	{}
	
	long get_id() const {
		return id_;
	}
	
	const string& get_name() const {
		return name_;
	}
	void print(){
		cout << "id: " << get_id() << ";name: " << get_name() << endl;
	}
	
};

class Manager: public Employee{
		int level_;
public:
	Manager(long id,string name,int level)
	:Employee(id,name),
		level_(level)
	{}
	
	
	int get_level() const {
		return level_;
	}
	
	void print(){
		cout<<"id: "<< get_id()<<";name: "<<get_name()<<"l"<<get_level()<<endl;
	}
	
	
};



int main () {
	Employee e1(1L," Pesho Peshev ");
	Employee e2(2L,"Ivan Ivanov");

	
	cout<<"e1: "<<e1.get_id()<<";"<<e1.get_name()<<endl;
	cout<<"e2: "<<e2.get_id()<<";"<<e2.get_name()<<endl;
	
	Manager m1(3L,"Gosho Goshev",3);
	cout<<"m3: "<< m1.get_id()<<";"<<m1.get_name()<<";"<<m1.get_level()<<endl;
	
	return 0;
}








