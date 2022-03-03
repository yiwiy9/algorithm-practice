#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> a(N), b(N), c(N);
  for (int i=0; i<N; i++) cin >> a[i] >> b[i] >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  long long res = 0;
  for (int i=0; i<N; i++) {
    // https://qiita.com/ganyariya/items/33f1326154b85db465c3
    auto a_cnt = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    auto c_cnt = c.end() - upper_bound(c.begin(), c.end(), b[i]);

    res += a_cnt * c_cnt;
  }
  cout << res << endl;
}
