#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int N;
vector<int> p;

int func(int i, int before_num, int cnt)
{
  if (i == N) return cnt;

  int num = ((before_num + 1) + N) % N;
  int max = 0;

  chmax(max, func(i+1, num, cnt));

  if (num == (((p[i] - 1) + N) % N)) {
    chmax(max, func(i+1, (((p[i] - 1) + N) % N), cnt+1));
  }
  if (num == ((p[i] + N) % N)) {
    chmax(max, func(i+1, ((p[i] + N) % N), cnt+1));
  }
  if (num == (((p[i] + 1) + N) % N)) {
    chmax(max, func(i+1, (((p[i] + 1) + N) % N), cnt+1));
  }

  return max;
}

int main()
{
  cin >> N;
  p.assign(N, 0);
  for (int i=0; i<N; i++) cin >> p[i];

  int max = 0;
  chmax(max, func(0, (((p[N] - 1) + N) % N), 0));
  chmax(max, func(0, ((p[N] + N) % N), 0));
  chmax(max, func(0, (((p[N] + 1) + N) % N), 0));
  cout << max << endl;
}
