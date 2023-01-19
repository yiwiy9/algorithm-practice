#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, string> G;

map<string, bool> seen, finished;
bool has_cycle = false;

void dfs(string v)
{
    seen[v] = true;

    if (G.find(v) == G.end())
    {
        return;
    }
    auto next_v = G[v];

    if (finished[next_v])
    {
        finished[v] = true;
        return; // 完全終了
    }

    if (seen[next_v] && !finished[next_v])
    { // サイクル検出
        has_cycle = true;
        return;
    }

    dfs(next_v);

    // サイクル検出したならば真っ直ぐに抜けていく
    if (has_cycle)
    {
        return;
    }

    finished[v] = true;
}

int main()
{
    int N;
    cin >> N;

    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i] >> T[i];
        G[S[i]] = T[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (seen[S[i]])
        {
            continue;
        }
        dfs(S[i]);
        if (has_cycle)
        {
            break;
        }
    }

    if (has_cycle)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}
