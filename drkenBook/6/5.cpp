#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

// N^2 個の整数のうち、x 以下の値が K 個以上あるかどうかを判定せよ
// left: false, right: true
int main()
{
  long long N, K;
  cin >> N >> K;
  vector<long long> a(N), b(N), c(N);
  for (long long i=0; i<N; i++) cin >> a[i];
  for (long long i=0; i<N; i++) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long left = 0, right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2;

    for (long long i=0; i<N; i++) {
      if (a[i] == 0) {
        c[i] = 0;
      } else {
        c[i] = mid / a[i];
      }
    }

    long long count = 0;
    for (long long i=0; i<N; i++) {
      auto iter = upper_bound(b.begin(), b.end(), c[i]);
      count += iter - b.begin();
    }

    if (count < K) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << right << endl;
}
