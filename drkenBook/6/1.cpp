#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  auto b = a;
  sort(b.begin(), b.end());

  for (int i=0; i<N; i++) {
    auto iter = lower_bound(b.begin(), b.end(), a[i]);
    int index = iter - b.begin();
    cout << index << endl;
  }
}
