#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;

  cout << '0';

  for (int i=0; i<3; i++) {
    cout << S[i];
  }

  cout << endl;
}
