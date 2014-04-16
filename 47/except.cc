#include <iostream>
using namespace std;


int main() {
  

  cin.exceptions(ios_base::badbit
		 | ios_base::failbit
		 | ios_base::eofbit);

  int i=0;

  try {

    while(true) {
      
      cin >> i;
      cout << "i=" << i << endl;
      
    }
  } catch(const ios_base::failure& ex) {
    cout << "ios_base::failure catched..." << endl;
  }

  return 0;
}
