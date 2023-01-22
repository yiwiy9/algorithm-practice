#include <iostream>
#include <vector>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_ac
 * https://twitter.com/e869120/status/1388674962823663619/photo/2
 * 区間に対する処理は「セグメント木」
 * - 区間上の値を更新する [O(logN)]
 * - 任意の区間上の最小値や合計値などを取得する [O(logN)]
 *
 * 遅延評価セグメント木
 * - 区間更新：[a, b) の値を x に更新する [O(logN), ノーマルだとO(NlogN)]
 * - 区間加算：[a, b) の値に x を加算する [O(logN), ノーマルだとO(NlogN)]
 *
 * セグメント木について
 * https://algo-logic.info/segment-tree/
 * https://betrue12.hateblo.jp/entry/2020/09/22/194541
 *
 * AC Library Lazy Segtree
 * https://atcoder.github.io/ac-library/document_ja/lazysegtree.html
 * チートシート
 * https://betrue12.hateblo.jp/entry/2020/09/23/005940
 */

// 初期設定はチートシート参照
using S = long long; // data: 各要素および区間取得結果の型
using F = long long; // lazy: 操作（写像）を表す値の型

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) { return max(a, b); }                  // 区間取得をどのような演算で行うか
S e() { return -INF; }                                // 全ての a に対して op(a, e) = op(e, a) = a を満たすもの（最大値取得なら-INF）
S mapping(F f, S x) { return (f == ID ? x : f); }     // 操作 f を各ノードが持つ data の値 x に対して作用させる関数
F composition(F f, F g) { return (f == ID ? g : f); } // 既にこれまでの操作（g）を溜めている lazy に対して、さらに新しい操作（f）を追加する関数
F id() { return ID; }                                 // 全ての a に対して mapping(id, a) = a となるもの

int main()
{
    int W, N;
    cin >> W >> N;

    vector<S> v(W);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    S L, R;
    for (int i = 0; i < N; i++)
    {
        cin >> L >> R;
        L--, R--;
        auto height = seg.prod(L, R + 1) + 1;
        seg.apply(L, R + 1, height);
        cout << height << endl;
    }
}

// template <class T>
// bool chmax(T &a, T b)
// {
//     if (a < b)
//     {
//         a = b;
//         return true;
//     }
//     return false;
// }

// int main()
// {
//     int W, N;
//     cin >> W >> N;

//     vector<int> L(N), R(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> L[i] >> R[i];
//     }

//     vector<int> H(W + 1, 0);
//     for (int i = 0; i < N; i++)
//     {
//         int max_h = 0;
//         for (int w = L[i]; w <= R[i]; w++)
//         {
//             chmax(max_h, H[w]);
//         }

//         int next_h = max_h + 1;
//         cout << next_h << endl;

//         for (int w = L[i]; w <= R[i]; w++)
//         {
//             H[w] = next_h;
//         }
//     }
// }
