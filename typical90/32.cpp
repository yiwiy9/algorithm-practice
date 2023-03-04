#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1 << 30;

template <class T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_af
 * https://twitter.com/e869120/status/1390074137192767489/photo/1
 * 小さい制約は順列全探索
 */
int main()
{
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    int M;
    cin >> M;

    vector<vector<bool>> dislike(N, vector<bool>(N));
    int X, Y;
    for (int i = 0; i < M; i++)
    {
        cin >> X >> Y;
        X--, Y--;
        dislike[X][Y] = true;
        dislike[Y][X] = true;
    }

    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        P[i] = i;
    }

    int ans = inf;
    do
    {
        int sum = 0;
        bool ok = true;
        for (int i = 0; i < N; i++)
        {
            sum += A[P[i]][i];
            if (i < N - 1 && dislike[P[i]][P[i + 1]])
            {
                ok = false;
            }
        }
        if (ok)
        {
            chmin(ans, sum);
        }
    } while (next_permutation(P.begin(), P.end()));

    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
