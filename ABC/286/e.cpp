#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

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

    // グラフ
    Graph G(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (S[i][j] == 'Y')
            {
                G[i].push_back(j);
            }
        }
    }

    vector<vector<pair<int, long long>>> dist(N, vector<pair<int, long long>>(N, {-1, -1}));
    for (int s = 0; s < N; s++)
    {
        queue<int> que;

        // 始点をキューに入れる
        dist[s][s] = {0, A[s]};
        que.push(s);

        while (!que.empty())
        {
            int v = que.front();
            que.pop();

            for (auto next_v : G[v])
            {
                int next_first = dist[s][v].first + 1;
                long long next_second = dist[s][v].second + A[next_v];
                if (dist[s][next_v].first == -1 || (dist[s][next_v].first == next_first && dist[s][next_v].first < next_second))
                {
                    dist[s][next_v] = {next_first, next_second};
                    que.push(next_v);
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

        if (dist[u][v].first == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dist[u][v].first << ' ' << dist[u][v].second << endl;
        }
    }
}
