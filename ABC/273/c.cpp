#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  auto B = A;
  sort(B.begin(), B.end());
  B.erase(unique(B.begin(), B.end()), B.end());

  vector<int> C(N);

  for (int i=0; i<N; i++) {
    int num = B.end() - upper_bound(B.begin(), B.end(), A[i]);
    C[num]++;
  }

  for (int i=0; i<N; i++) cout << C[i] << endl;
}
