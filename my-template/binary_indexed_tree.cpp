#include <iostream>
#include <vector>
using namespace std;

/**
 * https://algo-logic.info/binary-indexed-tree/
 * 計算量は全て O(logN)
 * 1-indexed の配列（計算が楽）
 * i に最後の 1 が立っているビットの加算・減算で i が含まれている区間和を index を取得
 * => i に最後の 1 が立っているビットは、（i & -i) で求められる
 *    => 負の数が「ビット反転+1」で表現されるため
 *       => ( (0110) | (1001) ) + 1 = 0
 */
template <class Abel>
struct BIT
{
    const Abel UNITY_SUM = 0; // to be set
    vector<Abel> dat;

    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) {}
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }

    /* a is 1-indexed */
    inline void add(int a, Abel x)
    {
        for (int i = a; i < (int)dat.size(); i += (i & -i))
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a)
    {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= (i & -i))
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b)
    {
        return sum(b - 1) - sum(a - 1);
    }

    /* debug */
    void print()
    {
        for (int i = 1; i < (int)dat.size(); i++)
            cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int main()
{
    vector<int> A;
    A = {8, 3, 6, 5, 2, 4, 1, 9, 7};
    int N = A.size();

    BIT<long long> bit(N);

    bit.print();

    // 転倒数（数列Aについて、i<jかつAi>Ajとなる組(i,j)の個数）
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        long long inv_num = i - bit.sum(A[i]); // BITの総和 - 自分より左側 ＝ 自分より右側
        sum += inv_num;
        bit.add(A[i], 1); // 自分の位置に1を足す

        cout << "A[i]: " << A[i] << endl;
        cout << "転倒数: " << inv_num << endl;
        bit.print();
    }
    cout << sum << endl;
}
