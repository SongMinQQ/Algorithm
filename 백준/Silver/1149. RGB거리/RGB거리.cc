#include <bits/stdc++.h>
using namespace std;

int houses[1002][3], cal[1002][3], n, result = 999999999;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++){
      cin >> houses[i][j];
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++){
      cal[i][j] = min(cal[i-1][(j+1) % 3], cal[i - 1][(j+2) % 3]) + houses[i-1][j];
      // cout << cal[i][j] << '\n';
    }
  }
  for(int i = 0; i < 3; i++){
    result = min(result, cal[n][i]);
  }
  cout << result;
}
