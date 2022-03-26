#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 30;

int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> a(N), b(N);
  for (int i=0; i<N; i++) cin >> a[i];
  for (int i=0; i<N; i++) cin >> b[i];

  int a_before = a[0], b_before = b[0];
  for (int i=1; i<N; i++) {
    bool a_add = false, b_add = false;
    if (a_before == inf && b_before == inf) {
      break;
    }

    if (a_before != inf) {
      if (abs(a[i] - a_before) <= K) {
        a_before = a[i];
        a_add = true;
      }
      if (abs(b[i] - a_before) <= K) {
        b_before = b[i];
        b_add = true;
      }
    }

    if (b_before != inf) {
      if (abs(a[i] - b_before) <= K) {
        a_before = a[i];
        a_add = true;
      }
      if (abs(b[i] - b_before) <= K) {
        b_before = b[i];
        b_add = true;
      }
    }

    if (!a_add) a_before = inf;
    if (!b_add) b_before = inf;
  }

  if (a_before == inf && b_before == inf) cout << "No" << endl;
  else cout << "Yes" << endl;
}
