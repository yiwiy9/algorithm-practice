#include <iostream>
#include <string>
using namespace std;
long long INF = 1LL << 60;

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
 * https://atcoder.jp/contests/abc286/tasks/abc286_c
 * 最初に A 円払う操作を何回かしてから B 円払う操作を何回か行うというように操作の順序を決め打っていい
 * => A 円払う操作の回数を **全探索**
 *    都度 一致しない文字に関して B 円払う操作をおこなう
 */
int main()
{
    int N;
    long long A, B;
    string S;
    cin >> N >> A >> B >> S;

    // 移動後の添字の計算を楽するために繋げる
    S += S;

    long long min = INF;
    for (int i = 0; i < N; i++)
    {
        long long num = A * i;
        for (int j = 0; j < N / 2; j++)
        {
            if (S[i + j] != S[N - 1 + i - j])
            {
                num += B;
            }
        }
        chmin(min, num);
    }

    cout << min << endl;
}
