#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  set<int> set;
  for (int i=0; i<N; i++) {
    set.insert(a[i]);
  }

  cout << set.size() << endl;
}
