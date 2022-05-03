#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

vector<int> dp;

int dfs(const Graph &G, int x)
{
  // すでに探索済みの場合、以後の遷移数のMAXを返す
  if (dp[x] != 0) return dp[x];

  // 遷移先がない場合、辺の数なので自身を含めない
  if (G[x].empty()) return 0;

  for (auto y: G[x]) {
    chmax(dp[x], dfs(G, y)+1); // 自身の分を足す
  }
  return dp[x];
}

int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N+1);
  for (int i=0; i<M; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
  }

  dp.assign(N+1, 0);
  int ans = 0;
  for (int i=1; i<=N; i++) {
    if (dp[i] != 0) continue;
    dfs(G, i);

    chmax(ans, dp[i]);
  }

  cout << ans << endl;
}
