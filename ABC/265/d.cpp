#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  long long N, P, Q, R;
  cin >> N >> P >> Q >> R;

  vector<long long> A(N), S(N+1), D(3);
  for (long long i=0; i<N; i++) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }
  D[0] = P;
  D[1] = P+Q;
  D[2] = P+Q+R;

  queue<long long> que;
  long long num = 0;
  int d = 0;
  for (int i=0; i<N; i++) {
    que.push(A[i]);
    num += A[i];

    if (num == D[d]) {
      d++;
      if (d == 3) break;
    }

    if (num > D[d]) {
      if (d == 0) {
        long long q = que.front();
        que.pop();
        num -= q;
      } else {

      }
    }
  }


  if (d == 3) cout << "Yes" << endl;
  else cout << "No" << endl;
}
