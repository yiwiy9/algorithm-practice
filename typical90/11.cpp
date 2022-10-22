#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_k
 * https://github.com/E869120/kyopro_educational_90/blob/main/sol/011-03.cpp
*/
int main()
{
  int N;
  cin >> N;

  vector<int> D(N), C(N);
  vector<long long> S(N);
  for (int i=0; i<N; i++) cin >> D[i] >> C[i] >> S[i];

  // 座標圧縮だと同じ数字の時D以外の値がズレる
  // auto D2 = D;
  // sort(D2.begin(), D2.end());
  // vector<int> sorted_D_idx(N);
  // for (int i=0; i<N; i++) {
  //   int idx = lower_bound(D2.begin(), D2.end(), D[i]) - D2.begin();
  //   sorted_D_idx[idx] = i;
  // }

  // tupleでソートする（デフォで先頭要素で並び替える）
	vector<tuple<int, int, long long>> tup;
	for (int i=0; i<N; i++) {
		tup.push_back(make_tuple(D[i], C[i], S[i]));
	}
	sort(tup.begin(), tup.end());
	for (int i=0; i<N; i++) {
		D[i] = get<0>(tup[i]);
		C[i] = get<1>(tup[i]);
		S[i] = get<2>(tup[i]);
	}

  vector<vector<long long>> dp(N+1, vector<long long>(5001));
  for (int i=0; i<N; i++) {
    for (int j=0; j<5000; j++) {
      chmax(dp[i+1][j], dp[i][j]);
      if (j+C[i] <= D[i]) {
        // j日目は使ってる
        chmax(dp[i+1][j+C[i]], dp[i][j] + S[i]);
      }
    }
  }

  long long ans = 0;
  for (int j=0; j<=5000; j++) chmax(ans, dp[N][j]);
  cout << ans << endl;
}
