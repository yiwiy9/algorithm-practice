#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> P(N);
  int N_pos = 0;
  for (int i=1; i<=N; i++) {
    cin >> P[i];
    if (P[i] == N) N_pos = i;
  }

  if (N_pos == N) {
    for (int i=1; i<=N; i++) {
      if (P[i] == 1) cout << N;
      else cout << P[i]-1;

      if (i == N) cout << endl;
      else cout << ' ';
    }
    return 0;
  }

  vector<int> Q;
  for (int i=N_pos+1; i<=N; i++) {
    Q.push_back(P[i]);
  }
  auto R = Q;
  sort(R.begin(), R.end());

  if (R == Q) {
    R.push_back(N);
    N_pos--;
  }
}
