#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

double binary_plus(double val1,double val2) {
	return val1+val2;
}
double binary_minus(double val1,double val2) {
	return val1-val2;
}
double binary_mult(double val1, double val2) {
	return val1*val2;
}


void post_binary(list<double>& context, 
				 double (*binary_op)(double, double) ) {

	if(context.size()<2) {
		cout << "OOPS! not enough arguments..." << endl;
		return;
	}
	double val2=context.back();
	context.pop_back();
	
	double val1=context.back();
	context.pop_back();
	
	double res=binary_op(val1,val2);
	context.push_back(res);
	cout << "res: " << res << endl;
}


/*
void post_plus(list<double>& context) {
	if(context.size()<2) {
		cout << "OOPS! not enough arguments..." << endl;
		return;
	}
	double val2=context.back();
	context.pop_back();
	
	double val1=context.back();
	context.pop_back();
	
	double res=val1+val2;
	context.push_back(res);
	
	cout << "(plus): " << res << endl;
}
void post_minus(list<double>& context) {
	if(context.size()<2) {
		cout << "OOPS! not enough arguments..." << endl;
		return;
	}
	double val2=context.back();
	context.pop_back();
	
	double val1=context.back();
	context.pop_back();
	
	double res=val1-val2;
	context.push_back(res);
	
	cout << "(minus): " << res << endl;
}
*/

void parse_double(const string& token, list<double>& context) {
	istringstream in(token);
	double val=0.0;
	in >> val;
	if(!in) {
		cout << "OOPS: can't parse double: " << token << endl;
	} else {
		// cout << "(parse_double): "<< val << endl;
		context.push_back(val);
	}
}

int main() {
	string token;
	
	list<double> context;
	
	while(cin) {
		cin >> token;
		
		if(!cin) {
			cout << "end of file..." << endl;
			break;
		}
		
		// cout << "token: " << token << endl;

		if(token=="+") {
			post_binary(context, binary_plus);
		} else if(token=="-") {
			post_binary(context, binary_minus);
		} else if(token=="*") {
			post_binary(context, binary_mult);		
		} else {
			parse_double(token, context);
		}
		
	}

	return 0;
}

