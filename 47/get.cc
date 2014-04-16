#include <iostream>
using namespace std;

int main() {
  char ch;
  while(cin) {
    // cin >> ch;
    cin.get(ch);

    if(!cin) {
      break;
    }
    cout << "ch: " << ch << endl;
  }


  return 0;
}
