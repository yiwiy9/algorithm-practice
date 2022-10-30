#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dist(int x1,int y1, int x2,int y2)
{
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

vector<int> X, Y;
bool is_square(int a, int b, int c, int d)
{
  int ab = dist(X[a],Y[a],X[b],Y[b]);
  int ac = dist(X[a],Y[a],X[c],Y[c]);
  int ad = dist(X[a],Y[a],X[d],Y[d]);

  if (ab == ac) { // ひし形の可能性があるから、対角線の長さが等しいことも確認する
    return ac == dist(X[b],Y[b],X[d],Y[d]) && ab == dist(X[c],Y[c],X[d],Y[d]) && ad == dist(X[c],Y[c],X[b],Y[b]);
  }
  if (ab == ad) {
    return ad == dist(X[c],Y[c],X[b],Y[b]) && ab == dist(X[c],Y[c],X[d],Y[d]) && ac == dist(X[b],Y[b],X[d],Y[d]);
  }
  if (ad == ac) {
    return ac == dist(X[b],Y[b],X[d],Y[d]) && ad == dist(X[c],Y[c],X[b],Y[b]) && ab == dist(X[c],Y[c],X[d],Y[d]);
  }
  return false;
}

int main()
{
  vector<string> field(9);
  for (int i=0; i<9; i++) cin >> field[i];

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      if (field[i][j] == '#') {
        X.push_back(i);
        Y.push_back(j);
      }
    }
  }

  int N = (int) X.size();
  int ans = 0;

  for (int a=0; a<N; a++) {
    for (int b=a+1; b<N; b++) {
      for (int c=b+1; c<N; c++) {
        for (int d=c+1; d<N; d++) {
          if (is_square(a,b,c,d)) {
            ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;
}
