#include <bits/stdc++.h>
using namespace std;

int n, A, B, C, D, E, F, ret;
map<int, int> m[10002];
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> A >> B >> C >> D >> E >> F;
    m[i][A] = F;
    m[i][F] = A;
    m[i][B] = D;
    m[i][D] = B;
    m[i][C] = E;
    m[i][E] = C;
  }
  for (int i = 1; i <= 6; i++){
    int top = i, btm = m[0][top];
    int result = 0;
    for (int j = 1; j <= n; j++){
      int maxNum = 0;
      for (int k = 1; k <= 6; k++){
        if(k == top || k == btm) continue;
        maxNum = max(maxNum, k);
      }
      result += maxNum;
      top = btm;
      btm = m[j][top];
    }
    ret = max(ret, result);
  }
  cout << ret;
  return 0;
}