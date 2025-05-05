#include<bits/stdc++.h>
using namespace std;

string line, result;
int cnt;
int main(){
  cin >> line;
  for(char i : line){
    if(i == 'X')
      cnt++;
    else{
      int aCnt = cnt / 4, bCnt = cnt % 4;
      cnt = 0;
      if(bCnt & 1){
        cout << -1;
        return 0;
      }
      while(aCnt--){
        result += "AAAA";
      }
      while(bCnt--){
        result += 'B';
      }
      result += i;
    }
  }
  int aCnt = cnt / 4, bCnt = cnt % 4;
  cnt = 0;
  if(bCnt & 1){
    cout << -1;
    return 0;
  }
  while(aCnt--){
    result += "AAAA";
  }
  while(bCnt--){
    result += 'B';
  }
  cout << result;
  return 0;
}