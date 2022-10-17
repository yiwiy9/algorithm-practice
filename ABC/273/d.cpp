#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int H, W, rs, cs, N;
  cin >> H >> W >> rs >> cs >> N;
  rs--, cs--;
  vector<vector<int>> row(H);
  vector<vector<int>> line(W);
  for (int i=0; i<N; i++) {
    int r, c;
    cin >> r >> c;
    r--, c--;

    row[r].push_back(c);
    line[c].push_back(r);
  }

  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    char d;
    int l;
    cin >> d >> l;

    if (d == 'U') {
      auto itr =
    }
  }
}
