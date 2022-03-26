#include <iostream>
#include <set>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int a;
  set<int> set;
  for (int i=0; i<N; i++) {
    cin >> a;
    set.insert(a);
  }

  int ans;
  for (int i=0; i<=2000; i++) {
    if (set.find(i) == set.end()) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}
