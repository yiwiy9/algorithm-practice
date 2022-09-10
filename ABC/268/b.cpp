#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;

  bool ok = true;
  for (int i=0; i<S.size(); i++) {
    if (i==T.size()) {
      ok = false;
      break;
    }
    if (S[i] != T[i]) ok = false;
  }


  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
