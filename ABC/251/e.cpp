#include <iostream>
#include <vector>
#include <set>
using namespace std;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;

  vector<long long> A(N+1);
  for (int i=1; i<=N; i++) cin >> A[i];

  long long left = 0, right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2;

    set<int> feeded;
    for (int i=1; i<=N; i++) {
      if (A[i] > mid) continue;
      if (i == N) {
        feeded.insert(N);
        feeded.insert(1);
      } else {
        feeded.insert(i);
        feeded.insert(i+1);
      }
    }

    if (feeded.size() >= N) {
      // mid は条件を十分に満たす
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << right << endl;
}
