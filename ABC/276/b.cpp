#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i=0; i<N; i++) sort(G[i].begin(), G[i].end());

  for (int i=0; i<N; i++) {
    int size = (int)G[i].size();
    cout << size;
    if (size == 0) cout << endl;
    else cout << ' ';

    for (int j=0; j<size; j++) {
      cout << G[i][j]+1;
      if (j == size-1) cout << endl;
      else cout << ' ';
    }
  }
}
