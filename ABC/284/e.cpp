#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int K = 0;
vector<bool> seen;
bool dfs(const Graph &G, int v)
{
    seen[v] = true;

    K++;
    if (K == 1000000)
    {
        return true;
    }

    for (auto next_v : G[v])
    {
        if (seen[next_v])
        {
            continue;
        }
        if (dfs(G, next_v))
        {
            return true;
        }
        seen[next_v] = false;
    }
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    dfs(G, 0);
    cout << K << endl;
}
