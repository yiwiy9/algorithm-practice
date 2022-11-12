#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, X;
  cin >> N >> X;

  vector<int> P(N);
  for (int i=0; i<N; i++) cin >> P[i];

  for (int i=0; i<N; i++) {
    if (P[i] == X) {
      cout << i + 1 << endl;
      break;
    }
  }
}
