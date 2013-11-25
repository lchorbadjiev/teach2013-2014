#include <iostream>
#include <string>
#include <list>
#include <sstream>
using namespace std;
/*
void post_plus(list<double>& context) {
	cout << "(plus)" << endl;
	
	if(context.size()<2) {
		cout << "OOPS! not enough arguments..." << endl;
		return;
	}
	
	double val2 = context.back();
	context.pop_back();
	
	double val1 = context.back();
	context.pop_back();
	
	double res = val1 + val2;
	context.push_back(res);
	
	cout << "res: " << res << endl;
}

void post_minus(list<double>& context) {
	cout << "(minus)" << endl;
	
	if(context.size()<2) {
		cout << "OOPS! not enough arguments..." << endl;
		return;
	}
	
	double val2 = context.back();
	context.pop_back();
	
	double val1 = context.back();
	context.pop_back();
	
	double res = val1 - val2;
	context.push_back(res);
	
	cout << "res: " << res << endl;
}
*/

void post_binary(list<double>& context, 
			     double (*binary_op)(double,double) ) {
			     // void (*func)()
			     // int (*func)(double, double)  
	if(context.size()<2) {
		cout << "OOPS! not enough arguments..." << endl;
		return;
	}
	
	double val2 = context.back();
	context.pop_back();
	
	double val1 = context.back();
	context.pop_back();
	
	double res = binary_op(val1, val2);
	context.push_back(res);
	
	cout << "res: " << res << endl;
}

double binary_plus(double val1, double val2) {
	return val1+val2;
}
double binary_minus(double val1, double val2) {
	return val1 - val2;
}
double binary_mult(double val1, double val2) {
	return val1* val2;
}

void post_double(const string& token, list<double>& context) {
	istringstream in(token);
	double val=0.0;
	in >> val;
	if(!in) {
		cout << "OOPS!! not a double?? " << token << endl;
	} else {
		cout << "(double): " << val << endl;
		context.push_back(val);
	}
}

int main() {
	string token;
	list<double> context;
	
	while(cin) {
	
		cin >> token;
		
		if(!cin) {
			cout << "OOPS: end of file..." << endl;
			break;
		}
		
		cout << "token: " << token << endl;
		if(token=="+") {
			//post_plus(context);
			post_binary(context, binary_plus);
		} else if(token=="-") {
			post_binary(context, binary_minus);
		} else if(token=="*") {
			post_binary(context, binary_mult);
		
		} else {
			post_double(token, context);
		}
		
		
		
	}


	return 0;
}
