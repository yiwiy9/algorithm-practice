#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  set<int> n;
  for (int i=0; i<N; i++) {
    if (A[i] <= W) {
      n.insert(A[i]);
    }
    for (int j=i+1; j<N; j++) {
      if (A[i] + A[j] <= W) {
        n.insert(A[i] + A[j]);
      }
      for (int r=j+1; r<N; r++) {
        if (A[i] + A[j] + A[r] <= W) {
          n.insert(A[i] + A[j] + A[r]);
        }
      }
    }
  }
  cout << n.size() << endl;
}
