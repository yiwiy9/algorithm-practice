#include <iostream>
#include <vector>
using namespace std;

/**
 * https://atcoder.jp/contests/abc245/tasks/abc245_c
 * 小問題に分けることができたら、大人しくDPを使え！
 * dp[]を２つ持っても良いことを知る
 */
int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> a(N), b(N);
  for (int i=0; i<N; i++) cin >> a[i];
  for (int i=0; i<N; i++) cin >> b[i];

  vector<bool> dp(N, false), ep(N, false);
  dp[0] = ep[0] = true;

  for (int i=1; i<N; i++) {
    if (dp[i-1]) {
      if (abs(a[i] - a[i-1]) <= K) dp[i] = true;
      if (abs(b[i] - a[i-1]) <= K) ep[i] = true;
    }

    if (ep[i-1]) {
      if (abs(a[i] - b[i-1]) <= K) dp[i] = true;
      if (abs(b[i] - b[i-1]) <= K) ep[i] = true;
    }
  }


  if (dp[N-1] || ep[N-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
