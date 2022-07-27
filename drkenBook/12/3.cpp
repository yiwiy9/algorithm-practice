#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  priority_queue<long long> low;  // 小さい順にK個管理する → top()が答えになる

  for (int i=0; i<N; i++) {
    long long a;
    cin >> a;

    if (i < K) {
      low.push(a);
      continue;
    }

    if (a < low.top()) {
      low.push(a);
      low.pop();
    }

    cout << low.top() << endl;
  }
}
