#include <iostream>
using namespace std;


// 最小値の更新
template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

// 最大値の更新
template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}



int main() {
  long long a = 42;
  long long b = 105;
  long long c = 20;

  chmax(a, b);
  cout << a << endl;
  chmax(a, c);
  cout << a << endl;
  chmin(a, c);
  cout << a << endl;
}
