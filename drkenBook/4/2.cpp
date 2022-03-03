#include <iostream>
#include <vector>
using namespace std;

int tribo(int i, vector<int> &memo)
{
  if (memo[i] != -1) return memo[i];

  if (i == 0) return memo[i] = 0;
  if (i == 1) return memo[i] = 0;
  if (i == 2) return memo[i] = 1;

  return memo[i] = tribo(i-1, memo) + tribo(i-2, memo) + tribo(i-3, memo);
}

int main()
{
  int N;
  cin >> N;

  vector<int> memo(N+1, -1);
  cout << tribo(N, memo) << endl;
}
