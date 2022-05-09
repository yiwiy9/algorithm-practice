#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, Q;
  cin >> N >> Q;

  vector<int> num(N+1), pos(N+1);
  for (int i=0; i<=N; i++) {
    num[i] = i;
    pos[i] = i;
  }

  int x, x_pos, y;
  for (int i=0; i<Q; i++) {
    cin >> x;
    x_pos = pos[x];
    if (x_pos==N) x_pos = N-1;

    x = num[x_pos];
    y = num[x_pos+1];

    num[x_pos] = y;
    num[x_pos+1] = x;
    pos[x] = x_pos+1;
    pos[y] = x_pos;
  }

  for (int i=1; i<=N; i++ ) cout << num[i] << ' ';
  cout << endl;
}
