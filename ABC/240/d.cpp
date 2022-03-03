#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  vector<pair<int, int>> b(N, {0,0});

  int cursor = 0;
  for (int i=0; i<N; i++) {
    if (cursor == 0) {
      b[cursor] = {a[i], 1};
      cursor++;
      cout << cursor << endl;
      continue;
    }

    auto before = b[cursor-1];
    if (before.first != a[i]) {
      b[cursor] = {a[i], 1};
      cursor++;
      cout << cursor << endl;
      continue;
    }

    if (before.second + 1 != a[i]) {
      b[cursor] = {a[i], before.second + 1};
      cursor++;
      cout << cursor << endl;
      continue;
    }

    cursor += 1 - a[i];
    cout << cursor << endl;
  }
}
