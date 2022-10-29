#include <iostream>
using namespace std;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  long long N, A, B, C;
  cin >> N >> A >> B >> C;

  long long ans = 10000;
  for (int i=0; i<=9999; i++) {
    for (int j=0; i+j<=9999; j++) {
      if (N-A*i-B*j >= 0 && (N-A*i-B*j) % C == 0) {
        chmin(ans, i+j+(N-A*i-B*j)/C);
      }
    }
  }

  cout << ans << endl;
}
