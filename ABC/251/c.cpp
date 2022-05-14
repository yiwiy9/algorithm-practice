#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<string> S(N+1);
  vector<int> T(N+1);
  for (int i=1; i<=N; i++) {
    cin >> S[i];
    cin >> T[i];
  }

  pair<int, int> max; // {Ti, i}
  max = {-1, -1};
  set<string> original;
  for (int i=1; i<=N; i++) {
    if (original.find(S[i]) != original.end()) continue;
    original.insert(S[i]);

    if (T[i] <= max.first) continue;
    max = {T[i], i};
  }

  cout << max.second << endl;
}
