#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, v;
  cin >> N >> v;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  int sum = 0;
  for (int i=0; i<N; i++) {
    if (a[i] == v) {
      sum++;
    }
  }

  cout << sum << endl;
}
