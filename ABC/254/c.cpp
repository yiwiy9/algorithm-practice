#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  vector<vector<int>> A(K);
  int a;
  for (int i=0; i<N; i++) {
    cin >> a;
    A[i%K].push_back(a);
  }

  for (int j=0; j<K; j++) {
    sort(A[j].begin(), A[j].end());
  }

  int col = (N/K)+1;
  bool ok = true;
  int before = 0;
  for (int r=0; r<col; r++) {
    for (int j=0; j<K; j++) {
      if ((r*K)+j == N) break;

      if (before > A[j][r]) {
        ok = false;
        break;
      }

      before = A[j][r];
    }
    if (!ok) break;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
