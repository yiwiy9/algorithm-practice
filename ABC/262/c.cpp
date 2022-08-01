#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N+1);
  for (int i=1; i<=N; i++) cin >> A[i];

  int same = 0;
  long long ans = 0;
  for (int i=1; i<=N; i++) {
    if (i == A[i]) same++;
    else if (A[i] > i) {
      if (A[A[i]] == i) ans++;
    }
  }

  ans += (long long)same*(same-1)/2;
  cout << ans << endl;
}
