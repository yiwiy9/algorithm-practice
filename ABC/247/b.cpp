#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<string> s(N), t(N);
  for (int i=0; i<N; i++) {
    cin >> s[i];
    cin >> t[i];
  }

  bool ok = true;
  for (int i=0; i<N; i++) {
    bool s_ok = true;
    bool t_ok = true;

    for (int j=0; j<N; j++) {
      if (i == j) continue;
      if (s[i] == s[j] || s[i] == t[j]) s_ok = false;
      if (t[i] == s[j] || t[i] == t[j]) t_ok = false;
    }

    if (!s_ok && !t_ok) {
      ok = false;
      break;
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
