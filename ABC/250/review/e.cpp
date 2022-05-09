#include <iostream>
#include <set>
#include <vector>
using namespace std;


/**
 * https://atcoder.jp/contests/abc250/tasks/abc250_e
 */
int main()
{
  int N;
  cin >> N;

  vector<int> A(N+1), B(N+1);
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) cin >> B[i];

  int ai, bi;
  ai = bi = 0;
  set<int> Sv, Sa, Sb;
  vector<bool> is_same(N+1, false); // keyは集合のサイズ
  vector<int> a_size(N+1), b_size(N+1);
  for (int i=1; i<=N; i++)
  { // i は集合のサイズと対応する
    while (ai < N)
    {
      ai++;
      if (Sa.find(A[ai]) == Sa.end()) { // Aにおいて同じ数字が出てきていない場合 == 集合のサイズが増える場合
        Sa.insert(A[ai]);
        a_size[ai] = i;

        if (Sv.find(A[ai]) != Sv.end()) {
          Sv.erase(A[ai]);
        } else {
          Sv.insert(A[ai]);
        }

        break;
      }
      a_size[ai] = i-1;
    }

    while (bi < N)
    {
      bi++;
      if (Sb.find(B[bi]) == Sb.end()) { // Bにおいて同じ数字が出てきていない場合 == 集合のサイズが増える場合
        Sb.insert(B[bi]);
        b_size[bi] = i;

        if (Sv.find(B[bi]) != Sv.end()) {
          Sv.erase(B[bi]);
        } else {
          Sv.insert(B[bi]);
        }

        break;
      }
      b_size[bi] = i-1;
    }

    is_same[i] = Sv.empty();
  }

  int Q;
  cin >> Q;

  int x, y;
  for (int i=0; i<Q; i++)
  {
    cin >> x >> y;

    if (a_size[x] != b_size[y]) {
      cout << "No" << endl;
      continue;
    }

    if (!is_same[a_size[x]]) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
  }
}
