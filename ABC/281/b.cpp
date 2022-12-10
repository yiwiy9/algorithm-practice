#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int size = (int) S.size();

  if (S[0] < 'A' || S[0] > 'Z') {
    cout << "No" << endl;
    return 0;
  }

  if (S[size-1] < 'A' || S[size-1] > 'Z') {
    cout << "No" << endl;
    return 0;
  }

  long long digit = 1;
  long long num = 0;
  bool ok = true;
  for (int i=size-2; i > 0; i--) {
    if (S[i] < '0' || S[i] > '9') {
      ok = false;
      break;
    }

    num += (long long)(S[i] - '0') * digit;
    digit *= 10;
  }

  if (num >= 1000000 || num < 100000) ok = false;

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
