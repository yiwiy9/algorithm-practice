#include <iostream>
#include <set>
using namespace std;


/**
 * https://atcoder.jp/contests/abc241/tasks/abc241_d
 *
 * multiset という、同じ値を複数取れる set データ構造を使う
 * ちなみに、setも順序を保持する → シンプルな集合は、unordered_set
 * http://vivi.dyndns.org/tech/cpp/multiset.html
 */
int main()
{
  int Q;
  cin >> Q;

  int c;
  long long x;
  int k;
  multiset<long long> st;
  for (int i=0; i<Q; i++) {
    cin >> c >> x;

    if (c == 1) {
      st.insert(x);
      continue;
    }

    cin >> k;

    if (c == 2) {
      auto itr = st.upper_bound(x);
      if (itr == st.begin()) {
        cout << -1 << endl;
        continue;
      }

      bool ok = true;
      for (int j=1; j<=k; j++) {
        itr--;
        if (itr == st.begin() && j != k) {
          ok = false;
          break;
        }
      }

      if (ok) cout << *itr << endl;
      else cout << -1 << endl;
      continue;
    }

    auto itr = st.lower_bound(x);
    if (itr == st.end()) {
      cout << -1 << endl;
      continue;
    }

    bool ok = true;
    for (int j=1; j<=k-1; j++) {
      itr++;
      if (itr == st.end() && j != k) {
        ok = false;
        break;
      }
    }

    if (ok) cout << *itr << endl;
    else cout << -1 << endl;
    continue;
  }
}
