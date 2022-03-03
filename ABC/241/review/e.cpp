#include <iostream>
#include <vector>
using namespace std;

/**
 * https://atcoder.jp/contests/abc241/tasks/abc241_e
 */
int main()
{
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }

  vector<long long> S(N); // 合計
  vector<int> pre(N, -1); // 呼び出された順番
  S[0] = 0;
  pre[0] = 0;
  int begin, end;
  for (int i=0; i<N; i++) {
    S[i+1] = S[i] + A[S[i]%N];
    if (pre[S[i+1] % N] != -1) {
      begin = pre[S[i+1] % N];
      end = i + 1;
      break;
    }
    pre[S[i+1] % N] = i + 1;
  }

  if (K < end) {
    cout << S[K] << endl;
    return 0;
  }

  int dist = end - begin;
  long long loop_sum = S[end] - S[begin];
  long long loop_cnt = (K - begin + 1) / dist;
  int rest_cnt = (K - begin + 1) % dist;
  long long rest = S[rest_cnt + 1]; // ループの始まりまで + ループの終わりからKまで
  long long ans = rest + (loop_sum*loop_cnt);
  cout << ans << endl;
}
