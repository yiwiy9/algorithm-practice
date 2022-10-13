#include <iostream>
#include <vector>
const int inf = 1 << 30;

using namespace std;

int main()
{
  int N, L, K;
  cin >> N >> L >> K;
  vector<int> A(N+1);
  for (int i=0; i<N; i++) cin >> A[i];
  A[N] = L;

  int left = 0, right = inf;
  while (right - left > 1) {
    int mid = (left + right) / 2;

    int cnt = 0;
    int before_cut = 0;
    for (int i=0; i<=N; i++) {
      if (A[i] - before_cut >= mid) {
        cnt++;
        before_cut = A[i];
      }
    }

    if (cnt >= K+1) left = mid;
    else right = mid;
  }

  cout << left << endl;
}
