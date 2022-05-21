#include <iostream>
#include <vector>
#include <set>
using namespace std;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N+1);

  int max = 0;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    chmax(max, A[i]);
  }

  set<int> max_i;
  for (int i=1; i<=N; i++) {
    if (A[i] == max) max_i.insert(i);
  }

  int b;
  bool ok = true;
  for (int i=0; i<K; i++) {
    cin >> b;
    if (max_i.find(b) != max_i.end()) {
      ok = false;
      break;
    }
  }

  if (ok) cout << "No" << endl;
  else cout << "Yes" << endl;
}
