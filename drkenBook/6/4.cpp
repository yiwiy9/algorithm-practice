#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

int main()
{
  long long N, M;
  cin >> N >> M;
  vector<long long> a(N);
  for (long long i=0; i<N; i++) cin >> a[i];

  long long left = 0, right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2;

    long long before_selected = 0;
    long long selected_cnt = 0;
    for (long long i=0; i<N; i++) {
      if (a[i] - before_selected < mid) continue;
      before_selected = a[i];
      selected_cnt++;
    }

    if (selected_cnt >= M) {
      // mid は条件を十分に満たす
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << left << endl;
}
