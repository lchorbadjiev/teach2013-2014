#include <iostream>
using namespace std;


int main() {
  cout.setf(ios_base::showbase);
  cout.setf(ios_base::oct, ios_base::basefield);
  cout << 1234 << ' ' << 1234 << endl;

  cout.setf(ios_base::hex, ios_base::basefield);
  cout << 1234 << ' ' << 1234 << endl;

  cout.setf(ios_base::dec, ios_base::basefield);
  cout << 1234 << ' ' << 1234 << endl;

  return 0;
}
