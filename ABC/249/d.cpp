#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  sort(A.begin(), A.end());

  long long left = 0, right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    auto iter = lower_bound(A.begin(), A.end(), mid*a_k);
  }
}
