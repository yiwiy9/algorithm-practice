#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <atcoder/string>
using namespace std;
using namespace atcoder;

/**
 * https://atcoder.jp/contests/abc284/tasks/abc284_f
 * https://atcoder.jp/contests/abc284/editorial/5469
 * https://snuke.hatenablog.com/entry/2014/12/03/214243
 *
 * Z algorithm を使う
 *   文字列 S が与えられる。
 *   S の i 文字目以降のみを取り出した文字列を S[i:] とおく。
 *   0 以上 ∣S∣ 未満の全ての i に対して、
 *   S と S[i:] の最大共通接頭辞の長さ (S と S[i:] が先頭から何文字一致しているか) を求めよ。
 */
int main()
{
    int N;
    string T;
    cin >> N >> T;

    string A = T.substr(0, N);
    string B = T.substr(N);
    reverse(B.begin(), B.end());

    string X = A + B;
    vector<int> Z_X = z_algorithm(X);
    Z_X.push_back(0); // 便宜上、範囲外分も追加する(Z_Y[N]=Nのとき用)

    string Y = B + A;
    vector<int> Z_Y = z_algorithm(Y);
    Z_Y.push_back(0);

    for (int i = 0; i <= N; i++)
    {
        if (Z_X[2 * N - i] >= i && Z_Y[N + i] >= N - i)
        {
            cout << T.substr(0, i) + T.substr(N + i) << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
