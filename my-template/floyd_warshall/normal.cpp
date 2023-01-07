#include <iostream>
#include <vector>
using namespace std;

// 無限大を表す値
const long long INF = 1LL << 60;

/**
 * フロイド・ワーシャル法
 * 計算量：O(|V|^3)
 * 使い所：全頂点間についての最短路長を求める（負の重みの辺ありでも可）
 * 注意：グラフの遷移に基づいて緩和しないので、(INF + 負の数）で緩和される可能性がある
 *      => これは到達不可能としたい（INFとして扱いたい）
 */
int main()
{
    // 頂点数，辺数
    int N, M;
    cin >> N >> M;

    // dp 配列 (INF で初期化します)
    vector<vector<long long>> dp(N, vector<long long>(N, INF));

    // dp 初期条件
    for (int e = 0; e < M; e++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    for (int v = 0; v < N; v++)
        dp[v][v] = 0;

    // dp 遷移 (フロイド・ワーシャル法)
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dp[i][k] != INF && dp[k][j] != INF)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    // 結果出力
    // もし dp[v][v] < 0 なら負閉路が存在する
    bool exist_negative_cycle = false;
    for (int v = 0; v < N; v++)
    {
        if (dp[v][v] < 0)
            exist_negative_cycle = true;
    }
    if (exist_negative_cycle)
    {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j)
                    cout << " ";
                if (dp[i][j] != INF)
                    cout << dp[i][j];
                else
                    cout << "INF";
            }
            cout << endl;
        }
    }
}
