#include <iostream>
#include <vector>
#include <set>
using namespace std;

using Point = pair<long long, long long>;

const long long MOD = 998244353;

long long N, M, A, B, C, D, E, F;
set<Point> s;
long long func(Point p, int n) {
  if (n==N) return 1;

  long long sum = 0;

  if (s.find({p.first+A, p.second+B}) == s.end()) {
    sum += func({p.first+A, p.second+B}, n+1);
    sum %= MOD;
  }
  if (s.find({p.first+C, p.second+D}) == s.end()) {
    sum += func({p.first+C, p.second+D}, n+1);
    sum %= MOD;
  }
  if (s.find({p.first+E, p.second+F}) == s.end()) {
    sum += func({p.first+E, p.second+F}, n+1);
    sum %= MOD;
  }

  return sum;
}

int main()
{
  cin >> N >> M >> A >> B >> C >> D >> E >> F;

  for (int i=0; i<M; i++) {
    long long x, y;
    cin >> x >> y;
    s.insert({x,y});
  }

  cout << func({0,0}, 0) << endl;
}
