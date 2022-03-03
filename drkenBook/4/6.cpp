#include <iostream>
#include <vector>
using namespace std;

int rec(int i, int w, vector<int> &a, vector<vector<int>> &memo)
{
  if (i == 0) {
    if (w == 0) {
      return 1;
    }
    return 0;
  }

  if (memo[i][w] != -1) return memo[i][w];

  memo[i][w] = rec(i-1, w-a[i-1], a, memo);
  if (memo[i][w]) return 1;

  return memo[i][w] = rec(i-1, w, a, memo);
}

int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  vector<vector<int>> memo(N+1, vector<int>(W+1, -1));
  cout << rec(N, W, a, memo) << endl;
}
