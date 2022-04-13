#include <iostream>
#include <vector>
using namespace std;

using Ball = pair<long long, long long>;

int main()
{
  long long N;
  cin >> N;
  vector<Ball> line;

  long long q, x, c;
  long long index = 0;
  for (long long i=0; i<N; i++) {
    cin >> q;

    if (q == 1) {
      cin >> x >> c;
      line.push_back(Ball(x, c));
      continue;
    }

    cin >> c;
    long long ans = 0;
    while (c > 0) {
      Ball current_ball = line[index];

      if (current_ball.second > c) {
        ans += current_ball.first * c;
        current_ball.second -= c;
        line[index] = current_ball;
        break;
      }
      index++;

      ans += current_ball.first * current_ball.second;
      c -= current_ball.second;
    }
    cout << ans << endl;
  }
}
