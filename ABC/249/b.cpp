#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char ToUpper (char cX) { return toupper(cX); }
char ToLower (char cX) { return tolower(cX); }

int main()
{
  string S, S_U, S_L;
  cin >> S;

  S_U = S;
  S_L = S;

  transform(S_U.begin(), S_U.end(), S_U.begin(), ToUpper);
	transform(S_L.begin(), S_L.end(), S_L.begin(), ToLower);
  if (S == S_U || S == S_L) {
    cout << "No" << endl;
    return 0;
  }

  bool ok = true;
  for (int i=0; i<S.size(); i++) {
    for (int j=i+1; j<S.size(); j++) {
      if (S[i] == S[j]) ok = false;
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
