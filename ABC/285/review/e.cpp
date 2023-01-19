#include <iostream>
#include <vector>
using namespace std;

template <class T>
bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

/**
 * https://atcoder.jp/contests/abc285/tasks/abc285_e
 * 例えば、曜日2〜曜日N+1を１週間としても、答えは変わらない
 * => 円環上の問題
 * => 円環上で問題を解く際は、特別な意味のあるものを先頭に固定するのが定石
 * => 今回は、「休日」(のうち１つ)を曜日1に固定する
 *
 * 問題の性質から、「休日の間に挟まる平日の数が決まれば、その間の生産量が確定する」ことがわかる
 * 「休日」同士の間隔がd日であるとすると、
 * - d=0 のとき 0
 * - d=1 のとき A1
 * - d=2 のとき 2×A1
 * - d=3 のとき 2×A1+A2
 * - d=4 のとき 2×A1+2×A2
 * => B[d] = Σ(1~d) A(i+1/2)
 *
 * dp[何曜日まで割り当てを決めたか][現在連続している平日の数]={ 生産量の最大値 }
 * => dp[i][j]    を dp[i+1][j+1] に遷移
 * => dp[i][j]+Bj を dp[i+1][0] に遷移
 * => dp[0][0]=0 (「休日」(のうち１つ)を曜日1に固定)
 */
int main()
{
    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (i + 1 < N)
        {
            B[i + 1] = B[i] + A[i / 2];
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(N, -1));

    dp[0][0] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (dp[i][j] == -1)
            {
                continue;
            }
            chmax(dp[i + 1][j + 1], dp[i][j]);
            chmax(dp[i + 1][0], dp[i][j] + B[j]);
        }
    }

    long long ans = -1;
    for (int j = 0; j < N; j++)
    {
        // 最後の休日から固定した週初めの休日までの間の生産量B[j]を足す
        chmax(ans, dp[N - 1][j] + B[j]);
    }
    cout << ans << endl;
}
