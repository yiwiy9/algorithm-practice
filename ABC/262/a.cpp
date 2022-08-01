#include <iostream>
using namespace std;

int main()
{
  int Y;
  cin >> Y;

  int amari = Y % 4;

  if (amari == 2) cout << Y << endl;
  else if (amari == 0) cout << Y + 2 << endl;
  else cout << Y + amari << endl;
}
