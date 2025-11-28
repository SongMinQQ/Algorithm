#include<bits/stdc++.h>
using namespace std;

int m[102][102], x1, x2, y, y2, ret;
int main(){
  int n = 4;
  while(n--){
    cin >> x1 >> y >> x2 >> y2;
    for (int i = x1; i < x2; i++){
      for (int j = y; j < y2; j++){
        m[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < 101; i++){
    for (int j = 0; j < 101; j++){
      if(m[i][j])
        ret++;
    }
  }
  cout << ret;
  return 0;
}