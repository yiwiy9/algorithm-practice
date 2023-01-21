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
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<string> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    // dp 配列 (INF で初期化します)
    vector<vector<pair<long long, long long>>> dp(N, vector<pair<long long, long long>>(N, {INF, 0}));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (S[i][j] == 'Y')
            {
                dp[i][j] = {1, A[j]};
            }
        }
    }
    for (int v = 0; v < N; v++)
    {
        dp[v][v].first = 0;
    }

    // dp 遷移 (フロイド・ワーシャル法)
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            { // 今回は負の辺が存在しない == 負閉路は存在しない
                if (dp[i][k].first + dp[k][j].first < dp[i][j].first)
                {
                    dp[i][j].first = dp[i][k].first + dp[k][j].first;
                    dp[i][j].second = dp[i][k].second + dp[k][j].second;
                }
                else if (dp[i][k].first + dp[k][j].first == dp[i][j].first && dp[i][k].second + dp[k][j].second > dp[i][j].second)
                {
                    dp[i][j].second = dp[i][k].second + dp[k][j].second;
                }
            }
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (dp[u][v].first == INF)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dp[u][v].first << ' ' << dp[u][v].second + A[u] << endl;
        }
    }
}
