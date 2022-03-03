#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  vector<int> b;
  int before = 0;
  for (int i=0; i<N; i++) {
    int angle = before + a[i];
    if (angle >= 360) {
      angle -= 360;
    }
    b.push_back(angle);
    before = angle;
  }
  b.push_back(360);

  sort(b.begin(), b.end());

  before = 0;
  int max = -1;
  for (int j=0; j<N+1; j++) {
    int diff = b[j] - before;
    if (diff > max) {
      max = diff;
    }
    before = b[j];
  }

  cout << max << endl;
}
