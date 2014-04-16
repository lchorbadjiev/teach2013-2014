#include <iostream>
#include <iomanip>
using namespace std;


int main() {

  cout << boolalpha << true << noboolalpha << false << endl;
  cout << 1234 << showbase << ' '
       << hex << 1234 << ' '
       << oct << 1234 << ' '
       << dec << 1234 << endl;

  cout << setprecision(12) << 123456.1234567 << endl;

  cout << '|' << setw(10) << 12 << '|' << endl;
  cout << '|' << setw(10) << 120 << '|' << endl;
  cout << '|' << setw(10) << 1200 << '|' << endl;
  cout << '|' << setw(10) << setfill('x') << 12000 << '|' << endl;
  
  return 0;
}
