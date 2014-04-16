#include <iostream>
using namespace std;

int main() {
  cout << 1234.56789 << ' ' << 1234.5678901 << endl;
  
  cout.precision(12);
  
  cout.setf(ios_base::scientific,
	    ios_base::floatfield);
  cout << 1234.56789 << ' ' << 1234.5678901 << endl;

  cout.setf(ios_base::fixed,
	    ios_base::floatfield);
  cout << 1234.56789 << ' ' << 1234.5678901 << endl;

  cout.setf(ios_base::floatfield);
  cout << 1234.56789 << ' ' << 123456.78901 << endl;

  return 0;
}
