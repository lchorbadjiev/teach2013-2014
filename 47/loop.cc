#include <iostream>
using namespace std;


int main() {
  int i=0;

  while(cin) {
    cin >> i;

    if(! cin) {
      cerr << "error!!!!" << endl;
      break;
    }

    cout << "i=" << i << endl;
  }

  return 0;
}
