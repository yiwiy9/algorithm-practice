#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> A;
  for (int i=0; i<N+K; i++) {
    int a;
    cin >> a;
    if (i < K) continue;
    if (i < N) A.push_back(a);
    else A.push_back(0);
  }

  for (int i=0; i<N; i++) {
    if (i != N-1) cout << A[i] << " ";
    else cout << A[i] << endl;
  }
}
