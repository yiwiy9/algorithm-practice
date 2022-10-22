#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> S1(N+1), S2(N+1);
  int C, P;
  for (int i=0; i<N; i++) {
    cin >> C >> P;
    if (C == 1) {
      S1[i+1] = S1[i] + P;
      S2[i+1] = S2[i];
    } else {
      S1[i+1] = S1[i];
      S2[i+1] = S2[i] + P;
    }
  }

  int Q, L, R;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    cin >> L >> R;
    cout << S1[R] - S1[L-1] << ' ';
    cout << S2[R] - S2[L-1] << endl;
  }
}
