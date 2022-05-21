#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int inf = 1 << 30;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}
template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  int N;
  cin >> N;

  vector<string> S(N);
  for (int i=0; i<N; i++) cin >> S[i];

  int min = inf;
  for (int num=0; num<10; num++)
  {
    map<int, int> map_cnt;

    for (int i=0; i<N; i++)
    {
      string s = S[i];
      for (int d=0; d<10; d++)
      {
        if (s[d] == ('0' + num)) {
          map_cnt[d]++;
          break;
        }
      }
    }

    int max_cnt = 0;
    for (int d=0; d<10; d++)
    {
      chmax(max_cnt, map_cnt[d]);
    }

    int max_d = 0;
    for (int d=0; d<10; d++)
    {
      if (map_cnt[d] == max_cnt) max_d = d;
    }

    int t = (max_cnt-1)*10 + max_d;
    chmin(min, t);
  }

  cout << min << endl;
}
