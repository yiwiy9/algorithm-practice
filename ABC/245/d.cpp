#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> A(N+1), B(M+1), C(N+M+1);
  for (int i=0; i<N+1; i++) cin >> A[i];
  for (int i=0; i<N+M+1; i++) cin >> C[i];

  for (int i=0; i<M+1; i++) {
    int b = C[i];
    for (int j=i; j>0; j--) {
      b -= A[j] * B[i-j];
    }
    if (A[0] != 0) {
      b /= A[0];
    }
    B[i] = b;
  }

  for (int i=0; i<M+1; i++) {
    cout << B[i] << " ";
  }
    cout << endl;
}
