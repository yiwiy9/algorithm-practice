#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
  int N, Q;
  cin >> N >> Q;

  map<int, set<int>> follow;

  int T, A, B;
  for (int i=0; i<Q; i++) {
    cin >> T >> A >> B;

    if (T == 1) {
      if (follow.find(A) == follow.end()) follow[A] = {};
      follow[A].insert(B);
    } else if (T == 2) {
      if (follow.find(A) != follow.end()) follow[A].erase(B);
    } else {
      if (follow.find(A) != follow.end() && follow.find(B) != follow.end() &&
          follow[A].find(B) != follow[A].end() && follow[B].find(A) != follow[B].end()) {
        cout << "Yes" << endl;
      } else cout << "No" << endl;
    }
  }
}
