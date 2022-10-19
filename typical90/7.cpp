#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  int Q;
  cin >> Q;
  int b, ans;
  for (int i=0; i<Q; i++) {
    cin >> b;

    auto lb_itr = lower_bound(A.begin(), A.end(), b);
    ans = abs(b - *lb_itr);

    if (lb_itr != A.begin()) {
      lb_itr--;
      ans = min(ans, abs(b - *lb_itr));
    }

    cout << ans << endl;
  }
}
