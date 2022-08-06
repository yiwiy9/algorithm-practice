#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> P(N+1);
  for (int i=2; i<=N; i++) {
    int p; cin >> p;
    P[i] = p;
  }

  int cur = N;
  int ans = 0;
  while (true) {
    if (cur == 1) break;
    cur = P[cur];
    ans++;
  }

  cout << ans << endl;
}
