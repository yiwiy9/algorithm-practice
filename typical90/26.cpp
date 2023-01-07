#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<vector<int>> dp;
void dfs1(const Graph &G, int v, int p = -1)
{
    for (auto c : G[v])
    {
        if (c == p)
        {
            continue;
        }
        dfs1(G, c, v);
    }

    dp[v][1] = 1;
    for (auto c : G[v])
    {
        if (c == p)
        {
            continue;
        }
        dp[v][1] += dp[c][0];
        dp[v][0] += dp[c][1];
    }
}

int N;
int select_cnt;
void dfs2(const Graph &G, bool is_select, int v, int p = -1)
{
    if (is_select && select_cnt < N / 2)
    {
        cout << v + 1;
        if (select_cnt < N / 2 - 1)
        {
            cout << ' ';
        }
        else
        {
            cout << endl;
        }
        select_cnt++;
    }

    for (auto c : G[v])
    {
        if (c == p)
        {
            continue;
        }
        dfs2(G, !is_select, c, v);
    }
}

/**
 * 「二部グラフの性質を使う」ともっと簡単にできる
 * https://twitter.com/e869120/status/1387538790017769474
 * => vector<bool> color(N) を深さ優先で埋めていくだけ
 *    = 二部グラフの塗り分け
 */
int main()
{
    cin >> N;

    Graph G(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dp.assign(N, vector<int>(2, 0));
    dfs1(G, 0);
    dfs2(G, dp[0][1] > dp[0][0], 0);
}
