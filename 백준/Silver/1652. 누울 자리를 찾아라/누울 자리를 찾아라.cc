#include<bits/stdc++.h>
using namespace std;

int n, cnt1, cnt2;
char mat[102][102];
void rightCheck(){
  for(int i = 0; i < n; i++){
    int place = 0;
    for(int j = 0; j < n; j++){
      if(mat[i][j] == '.') place++;
      else{
        if(place > 1) cnt1++;
        place = 0;
      }
    }
    if(place > 1) cnt1++;
  }
}
void bottomCheck(){
  for(int i = 0; i < n; i++){
    int place = 0;
    for(int j = 0; j < n; j++){
      if(mat[j][i] == '.') place++;
      else{
        if(place > 1) cnt2++;
        place = 0;
      }
    }
    if(place > 1) cnt2++;
  }
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> mat[i][j];
    }
  }
  rightCheck();
  bottomCheck();
  cout << cnt1 << ' ' << cnt2 << '\n';
  return 0;
}