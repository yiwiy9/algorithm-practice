#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  long long N, M;
  cin >> N >> M;

  vector<long long> X(N);
  for (int i=0; i<N; i++) cin >> X[i];

  vector<long long> C(M), Y(N);
  for (int i=0; i<M; i++) {
    long long c;
    cin >> c;
    C[i] = c-1;
    cin >> Y[C[i]];
  }

  long long ans = 0;
  for (int i=0; i<N; i++) {
    ans += X[i];
    ans += Y[i];
  }

  for (int j=0; j<M; j++) {
    long long sum = 0;
    int iter = 0;
    bool iter_init = false;
    for (int i=0; i<N; i++) {
      if (iter_init) {
        iter_init = false;
        continue;
      }
      sum += X[iter];
      sum += Y[iter];
      if (iter == C[j]) {
        iter = 0;
        iter_init = true;
        continue;
      }
      iter++;
    }
    chmax(ans, sum);

    int another_iter = C[j]+1;
    if (iter_init) {
      sum += X[another_iter];
      sum += Y[another_iter];
      chmax(ans, sum);
      continue;
    }
    if (iter == 0) iter++;

    for (int i=iter-1; i >=0; i--) {
      sum -= X[i];
      sum -= Y[i];
      sum += X[another_iter];
      sum += Y[another_iter];
      another_iter++;
    }
    chmax(ans, sum);
  }

  cout << ans << endl;
}
