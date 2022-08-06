#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> dp(N);

  bool ok = true;
  dp[0] = 1;
  while (ok) {
    for (int i=1; i<N; i++) {
      bool changed = false;
      for (int j=dp[i-1]+1; j<=M; j++) {
        if (dp[i] < j) {
          dp[i] = j;
          changed = true;
          break;
        }
      }
      if (!changed) {
        if (!ok) break;

        ok = false;
        dp[i-1]++;
        i--;
      } else {
        ok = true;
      }
    }

    for (int i=0; i<N; i++) {
      cout << dp[i];
      if (i!=N-1) cout << ' ';
      else cout << endl;
    }
  }
}
