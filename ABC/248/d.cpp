#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int a;
  vector<vector<int>> A(N+1);
  for (int i=1; i<=N; i++) {
    cin >> a;
    A[a].push_back(i);
  }

  vector<int> B;
  int Q, L, R, X;
  cin >> Q;

  for (int i=0; i<Q; i++) {
    cin >> L >> R >> X;

    B = A[X];

    auto left = lower_bound(B.begin(), B.end(), L);
    auto right = upper_bound(B.begin(), B.end(), R);

    cout << right - left << endl;
  }
}
