#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, M, T;
  cin >> N >> M >> T;

  vector<int> A(N-1), B(N-1);
  for (int i=0; i<N-1; i++) cin >> A[i];

  for (int i=0; i<M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    B[x] = y;
  }

  bool ok = true;
  for (int i=0; i<N-1; i++) {
    T -= A[i];
    T += B[i];
    if (T <= 0) {
      ok = false;
      break;
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
