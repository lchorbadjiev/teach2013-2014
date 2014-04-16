#include <iostream>
using namespace std;


int main() {
  cin.exceptions(ios_base::badbit 
		 | ios_base::failbit 
		 | ios_base::eofbit);

  int val;

  try {
    while(true) {
      cin >> val;
      cout << "val: " << val << endl;
    }
  } catch(ios_base::failure& ex) {
    cout << "io exception catched..." << endl;
  }
  return 0;
}
