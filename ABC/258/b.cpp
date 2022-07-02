#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
using Point = pair<int, int>;

const vector<Point> MOVE = {{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1},{0,1},{0,-1}};

int N;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

Point get_correct_point(Point p) {
  if (p.first == N) p.first = 0;
  if (p.first == -1) p.first = N-1;
  if (p.second == N) p.second = 0;
  if (p.second == -1) p.second = N-1;
  return p;
}

int main()
{
  cin >> N;

  vector<vector<int>> A(N, vector<int>(N));
  set<Point> st;
  int max = 0;
  for (int i=0; i<N; i++) {
    string line;
    cin >> line;

    int j=0;
    for (auto c : line) {
      int a = c - '0';
      A[i][j] = a;
      if (a > max) {
        max = a;
        st.clear();
        st.insert({i,j});
      } else if (a == max) {
        st.insert({i,j});
      }
      j++;
    }
  }

  long long ans = 0;
  for(auto itr = st.begin(); itr != st.end(); ++itr) {
    auto start_p = *itr;
    long long start = A[start_p.first][start_p.second] * pow(10, N-1);

    for (auto move: MOVE) {
      Point current_p = start_p;
      long long current = start;
      int n = N-2;
      for (int i=n; i>=0; i--) {
        current_p = get_correct_point({current_p.first+move.first, current_p.second+move.second});
        current += A[current_p.first][current_p.second] * pow(10, i);
      }
      chmax(ans, current);
    }

  }

  cout << ans << endl;
}
