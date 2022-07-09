#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;

  bool ans = true;
  bool can_add = false;
  char before_char;
  int s_i = 0;
  for (int t_i=0; t_i < T.size(); t_i++){
    if (S[s_i] == T[t_i]) {
      can_add = (S[s_i] == before_char);
      before_char = S[s_i];
      s_i++;
      continue;
    }

    if (!can_add || before_char != T[t_i]) {
      ans = false;
      break;
    }
  }

  if (ans) ans = (S.size() == s_i);

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
