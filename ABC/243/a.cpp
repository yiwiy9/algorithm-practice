#include <iostream>
using namespace std;

int main()
{
  int V, A, B, C;
  cin >> V >> A >> B >> C;

  V %= (A+B+C);

  if (V - A < 0) {
    cout << 'F' << endl;
  } else if (V - A - B < 0) {
    cout << 'M' << endl;
  } else {
    cout << 'T' << endl;
  }
}
