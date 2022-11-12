#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
  int N;
  cin >> N;

  vector<string> S(N);
  for (int i=0; i<N; i++) cin >> S[i];

  set<char> s1, s2;
  s1 = { 'H' , 'D' , 'C' , 'S' };
  s2 = { 'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K' };

  bool ok = true;
  for (int i=0; i<N; i++) {
    if (s1.find(S[i][0]) == s1.end()) ok = false;
    if (s2.find(S[i][1]) == s2.end()) ok = false;

    for (int j=0; j<N; j++) {
      if (j == i) continue;
      if (S[j] == S[i]) ok = false;
    }

    if (!ok) break;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
