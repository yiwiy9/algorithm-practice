#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
using Graph = map<long long, set<long long>>;

Graph G;
long long M;
map<long long, long long> memo;
map<long long, long long> cnt;
map<long long, bool> seen;
long long dfs(long long v)
{
  if (memo.find(v) != memo.end()) return memo[v];

  seen[v] = true;

  long long max_sum = 0;
  for (auto next_v : G[v]) {
    if (seen.find(next_v) != seen.end() && memo.find(next_v) == memo.end()) continue;
    max_sum = max(max_sum, dfs(next_v));
  }

  memo[v] = max_sum + (v * cnt[v]);
  return memo[v];
}

int main()
{
  int N;
  cin >> N >> M;

  long long total = 0;
  vector<long long> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
    cnt[A[i]]++;
    total += A[i];

    G[A[i]].insert(A[i]);
    if (A[i] == 0) {
      G[M-1].insert(A[i]);
    } else {
      G[A[i]-1].insert(A[i]);
    }
  }

  long long max_num = 0;
  for (int i=0; i<N; i++) {
    max_num = max(max_num, dfs(A[i]));
  }

  cout << total - max_num << endl;
}
