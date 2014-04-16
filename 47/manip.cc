#include <iostream>
#include <iomanip>
using namespace std;


int main() {


  cout << showbase << 1234 << ' ' << hex << 1234 << ' ' 
       << oct << 1234 << ' ' << dec << 1234 << endl;

  cout << boolalpha << true << ' ' << false << endl;
  cout << noboolalpha << true << ' ' << false << endl;


  cout << setprecision(12) << 1.2345678901 << endl;
  cout << setprecision(10) << 1.2345678901 << endl;
  cout << setprecision(8) << 1.2345678901 << endl;

  cout << '|' << setw(12) << 12 << '|' << setw(12) << 12 << '|' << endl;
  cout << '|' << setw(12) << 123 << '|' << endl;
  cout << '|' << setw(12) << 1234 << '|' << endl;
  cout << '|' << setw(12) << setfill('x') << 12345 << '|' << endl;

  return 0;
}
