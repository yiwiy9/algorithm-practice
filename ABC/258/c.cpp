#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int N, Q; string S;
  cin >> N >> Q >> S;

  int start_i = 0;
  int t, x;
  for (int i=0; i<Q; i++) {
    cin >> t >> x;

    if (t == 1) {
      start_i += x;
      start_i %= N;
      continue;
    }

    x--;
    if (x - start_i >= 0) cout << S[x - start_i] << endl;
    else cout << S[N + x - start_i] << endl;
  }
}
