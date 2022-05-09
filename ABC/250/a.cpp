#include <iostream>
using namespace std;

int main()
{
  int H, W, R, C;
  cin >> H >> W >> R >> C;

  if (H==1 || W==1) {
    if (R==1 && C==1) cout << 0 << endl;
    else if ((R == 1 || R == H || C == 1 || C == W)) {
      if ((R==1 && C==1) || (R==H && C==1) || (R==1 && C==W) || (R==H && C==W)) cout << 1 << endl;
      else cout << 2 << endl;
    }
    else cout << 2 << endl;
    return 0;
  }

  if ((R == 1 || R == H || C == 1 || C == W)) {
    if ((R==1 && C==1) || (R==H && C==1) || (R==1 && C==W) || (R==H && C==W)) cout << 2 << endl;
    else cout << 3 << endl;
  }
  else cout << 4 << endl;
}
