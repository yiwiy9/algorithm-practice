#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 30;

/**
 * https://algo-logic.info/binary-indexed-tree/
 * 計算量は全て O(logN)
 * 1-indexed の配列（計算が楽）
 * i に最後の 1 が立っているビットの加算・減算で i が含まれている区間和を index を取得
 * => i に最後の 1 が立っているビットは、（i & -i) で求められる
 *    => 負の数が「ビット反転+1」で表現されるため
 *       => ( (0110) | (1001) ) + 1 = 0
 */
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0; // to be set
    vector<Abel> dat;

    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
      for (int i = a; i < (int)dat.size(); i += (i & -i))
        dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
      Abel res = UNITY_SUM;
      for (int i = a; i > 0; i -= (i & -i))
        res = res + dat[i];
      return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
      return sum(b - 1) - sum(a - 1);
    }

    /* debug */
    void print() {
      for (int i = 1; i < (int)dat.size(); i++) cout << sum(i, i + 1) << ",";
      cout << endl;
    }
};

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }

  // 1, -1 の累積和を格納するため（A[i]の種類は最大N）
  const int indexed = N+1;

  int left = 0, right = inf;
  while (right - left > 1)
  {
    int mid = (left + right) / 2;

    long long num = 0;

    // BITが取りうる値のMAXを格納する
    BIT<long long> bit(2*indexed);

    // 1, -1 の累積和を格納する
    // 初期値（sum=0）のフラグを立てる
    int sum = 0;
    bit.add(sum+indexed, 1);

    for (int i=0; i<N; i++) {
      int val;
      if (A[i] <= mid) val = 1;
      else val = -1;

      // 累積和の更新
      sum += val;
      // 累積和の各区間和の総和を取得して、足し上げる
      num += bit.sum(1, sum+indexed);
      // 累積和の位置にフラグを足す
      bit.add(sum+indexed, 1);
    }

    if (num > (long long) N*(N+1)/2/2) right = mid;
    else left = mid;
  }

  cout << right << endl;
}
