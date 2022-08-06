#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> dp;
void dfs(int num, int depth) {
  dp[depth] = num;

  if (depth == N-1) {
    for (int i=0; i<N; i++) {
      cout << dp[i];
      if (i != N-1) cout << ' ';
      else cout << endl;
    }
    return;
  }

  for (int j=num+1; j<=M; j++) {
    dfs(j, depth+1);
  }
}

/**
 * https://atcoder.jp/contests/abc263/tasks/abc263_c
 * 表示したい順番からDFSって想像できるやろ
 */
int main()
{
  cin >> N >> M;
  dp.assign(N, 0);

  for (int j=1; j<=M-N+1; j++) {
    dfs(j, 0);
  }
}
