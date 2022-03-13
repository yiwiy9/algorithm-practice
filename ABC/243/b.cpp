#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  unordered_set<int> set;
  int b, cnt1, cnt2;
  cnt1 = cnt2 = 0;

  for (int i=0; i<N; i++) {
    cin >> b;

    if (a[i] == b) {
      cnt1++;
      set.insert(b);
      continue;
    }

    if (set.find(a[i]) != set.end()) {
      cnt2++;
    } else {
      set.insert(a[i]);
    }

    if (set.find(b) != set.end()) {
      cnt2++;
    } else {
      set.insert(b);
    }
  }

  cout << cnt1 << endl;
  cout << cnt2 << endl;
}
