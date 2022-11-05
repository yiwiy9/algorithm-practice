#include <iostream>
#include <vector>
using namespace std;

/**
 * https://twitter.com/e869120/status/1383635232134287360/photo/1
 * 図を書く
 * => Ls<Lt<Rs<Rt || Lt<Ls<Rt<Rs が必要十分条件であることがわかる
 * => 全探索
*/
void solve1()
{
  int N, M;
  cin >> N >> M;

  vector<int> L(M), R(M);
  for (int i=0; i<M; i++) cin >> L[i] >> R[i];

  int ans = 0;
  for (int i=0; i<M; i++) {
    for (int j=i+1; j<M; j++) {
      if ((L[i]<L[j] && L[j]<R[i] && R[i]<R[j]) || (L[j]<L[i] && L[i]<R[j] && R[j]<R[i])) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  solve1();
}
