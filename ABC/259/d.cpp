#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
using Graph = vector<vector<long long>>;

double distance(long long x1,long long y1,long long x2,long long y2)
{
  return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

bool is_cross(double dist, long long r1, long long r2)
{
  if (r1 > r2) {
    long long tmp = r1;
    r1 = r2;
    r2 = tmp;
  }
  return (dist <= r1 + r2 && dist + r1 >= r2);
}

vector<bool> seen;
int dfs(const Graph &G, int v)
{
  seen[v] = true;
  for (auto next_v: G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v);
  }
}

int main()
{
  long long N, sx, sy, tx, ty;
  cin >> N >> sx >> sy >> tx >> ty;
  vector<long long> x(N), y(N), r(N);

  for (int i=0; i<N; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }

  Graph G(N);
  vector<int> start;
  vector<int> end;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      double dist = distance(x[i], y[i], x[j], y[j]);
      if (is_cross(dist, r[i], r[j])) {
        G[i].push_back(j);
      }
    }
    if (distance(x[i], y[i], sx, sy) == r[i]) {
      start.push_back(i);
    }
    if (distance(x[i], y[i], tx, ty) == r[i]) {
      end.push_back(i);
    }
  }

  bool ok = false;
  for (auto i : start) {
    seen.assign(N, false);
    dfs(G, i);
    for (auto j : end) {
      if (seen[j]) {
        ok = true;
        break;
      }
    }
    if (ok) break;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
