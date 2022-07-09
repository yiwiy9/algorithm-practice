#include <iostream>
using namespace std;

int main()
{
  int N, M, X, T, D;
  cin >> N >> M >> X >> T >> D;

  int ans = T;

  for (int i=N; i>=M; i--) {
    if (i>=X) continue;
    ans -= D;
  }
  cout << ans << endl;
}
