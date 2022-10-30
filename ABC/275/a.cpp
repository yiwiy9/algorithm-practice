#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  int max_h = 0;
  for (int i=0; i<N; i++) {
    cin >> H[i];
    max_h = max(max_h, H[i]);
  }

  for (int i=0; i<N; i++) {
    if (H[i] == max_h) cout << i+1 << endl;
  }
}
