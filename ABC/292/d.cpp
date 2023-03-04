#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> used_v;
vector<vector<int>> used_e;
bool bfs(const Graph &G, int s)
{
    queue<int> que;

    int v_cnt = 0, e_cnt = 0;

    // 始点をキューに入れる
    used_v[s] = true;
    v_cnt++;
    que.push(s);

    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        if (!used_v[v])
        {
            used_v[v] = true;
            v_cnt++;
        }

        for (auto next_v : G[v])
        {
            if (used_e[v][next_v] == 0)
                continue;
            used_e[v][next_v]--;
            used_e[next_v][v]--;
            e_cnt++;
            que.push(next_v);
        }
    }

    return v_cnt == e_cnt;
}

int main()
{
    int N, M;
    cin >> N >> M;

    Graph G(N);
    used_e.assign(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        used_e[a][b]++;
        used_e[b][a]++;
    }

    used_v.assign(N, false);
    for (int v = 0; v < N; v++)
    {
        if (used_v[v])
            continue;
        if (!bfs(G, v))
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
