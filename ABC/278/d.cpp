#include <iostream>
#include <map>
using namespace std;

int main()
{
  int N;
  cin >> N;

  long long base = 0;
  map<int,long long> add;
  for (int i=1; i<=N; i++) cin >> add[i];

  int Q;
  cin >> Q;
  int t, i, x;
  for (int q=0; q<Q; q++) {
    cin >> t;

    if (t == 1) {
      cin >> x;
      base = x;
      add.clear();
    } else if (t == 2) {
      cin >> i >> x;
      if (add.find(i) == add.end()) add[i] = x;
      else add[i] += x;
    } else {
      cin >> i;
      if (add.find(i) == add.end()) cout << base << endl;
      else  cout << base + add[i] << endl;
    }
  }
}
