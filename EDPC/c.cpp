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
  int N;
  cin >> N;

  vector<int> a(N), b(N), c(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
    cin >> b[i];
    cin >> c[i];
  }
  vector<long long> dp_a(N+1), dp_b(N+1), dp_c(N+1);

  for (int i=0; i<N; i++) {
    chmax(dp_a[i+1], dp_b[i] + b[i]);
    chmax(dp_a[i+1], dp_c[i] + c[i]);

    chmax(dp_b[i+1], dp_c[i] + c[i]);
    chmax(dp_b[i+1], dp_a[i] + a[i]);

    chmax(dp_c[i+1], dp_a[i] + a[i]);
    chmax(dp_c[i+1], dp_b[i] + b[i]);
  }

  long long ans = 0;
  chmax(ans, dp_a[N]);
  chmax(ans, dp_b[N]);
  chmax(ans, dp_c[N]);

  cout << ans << endl;
}
