#include <iostream>
using namespace std;

int main() {
  char buff[1024];
  
  while(cin) {

    cin.getline(buff, 5, '\n');
    if(! cin) {
      cout << "error" << endl;
      cout << cin.good() 
	   << cin.eof() 
	   << cin.fail() 
	   << cin.bad() << endl;
      break;
    }
    cout << "buff: " << buff << endl;
  }

  return 0;
}
