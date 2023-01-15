#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_ab
 * https://twitter.com/e869120/status/1388262816101007363/photo/1
 * 領域加算は二次元いもす法
 */
int main()
{
    int N;
    cin >> N;

    vector<vector<int>> cnt(1001, vector<int>(1001, 0));

    int lx, ly, rx, ry;
    for (int i = 0; i < N; i++)
    {
        // (min,min), (max,max)の点を`+1`, 他の２点を`-1`する
        cin >> lx >> ly >> rx >> ry;
        cnt[lx][ly]++;
        cnt[lx][ry]--;
        cnt[rx][ly]--;
        cnt[rx][ry]++;
    }

    // 横方向に累積和を取る
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            cnt[i][j] += cnt[i][j - 1];
        }
    }

    // 縦方向に累積和を取る
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            cnt[i][j] += cnt[i - 1][j];
        }
    }

    vector<int> ans(N + 1);
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (cnt[i][j] > 0)
            {
                ans[cnt[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << ans[i] << endl;
    }
}
