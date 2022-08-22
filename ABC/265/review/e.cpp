#include <iostream>
#include <vector>
#include <set>
using namespace std;

using Point = pair<long long, long long>;

const long long MOD = 998244353;

/**
 * https://atcoder.jp/contests/abc265/tasks/abc265_e
 *
 * dp[i][j][k] := i回の移動でワープ１をj回、ワープ２をk回、ワープ３をi-j-k回したときの場合の数
 */
int main()
{
  long long N, M, A, B, C, D, E, F;
  cin >> N >> M >> A >> B >> C >> D >> E >> F;

  set<Point> set;
  for (int i=0; i<M; i++) {
    long long x, y;
    cin >> x >> y;
    set.insert({x,y});
  }

  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(N+1, 0)));
  dp[0][0][0] = 1;
  for (int i=0; i<N; i++) {
    for (int j=0; j<=i; j++) {
      for (int k=0; k<=i-j; k++) {
        Point p = {A*j + C*k + E*(i-j-k), B*j + D*k + F*(i-j-k)};

        if (set.find({p.first+A, p.second+B}) == set.end()) {
          dp[i+1][j+1][k] += dp[i][j][k];
          dp[i+1][j+1][k] %= MOD;
        }
        if (set.find({p.first+C, p.second+D}) == set.end()) {
          dp[i+1][j][k+1] += dp[i][j][k];
          dp[i+1][j][k+1] %= MOD;
        }
        if (set.find({p.first+E, p.second+F}) == set.end()) {
          dp[i+1][j][k] += dp[i][j][k];
          dp[i+1][j][k] %= MOD;
        }
      }
    }
  }

  long long ans = 0;
  for (int j=0; j<=N; j++) {
    for (int k=0; k<=N; k++) {
      ans += dp[N][j][k];
      ans %= MOD;
    }
  }

  cout << ans << endl;
}
