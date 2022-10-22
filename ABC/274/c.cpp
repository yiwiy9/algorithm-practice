#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N+1);
  for (int i=1; i<=N; i++) cin >> A[i];

  vector<int> ans(2*N+2);
  for (int i=1; i<=N; i++) {
    ans[2*i] = ans[A[i]] + 1;
    ans[2*i+1] = ans[A[i]] + 1;
  }

  for (int i=1; i<=2*N+1; i++) cout << ans[i] << endl;
}
