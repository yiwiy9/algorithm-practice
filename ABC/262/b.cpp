#include <iostream>
#include <set>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  set<pair<int, int>> E;
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a<b) E.insert({a, b});
    else E.insert({b, a});
  }

  int ans = 0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      for (int k=j+1; k<N; k++) {
        if (E.find({i, j}) != E.end() && E.find({i, k}) != E.end() && E.find({j, k}) != E.end()) ans++;
      }
    }
  }

  cout << ans << endl;
}
