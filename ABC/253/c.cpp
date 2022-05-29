#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
  int Q;
  cin >> Q;

  set<int> S;
  map<int, int> M;
  int q, x, c;
  for (int i=0; i<Q; i++) {
    cin >> q;

    if (q == 3) {
      cout << *S.rbegin() - *S.begin() << endl;
      continue;
    }

    cin >> x;
    if (q == 1) {
      S.insert(x);
      M[x]++;
      continue;
    }

    cin >> c;
    if (M[x] - c > 0) {
      M[x] -= c;
      continue;
    }

    M[x] = 0;
    S.erase(x);
  }
}
