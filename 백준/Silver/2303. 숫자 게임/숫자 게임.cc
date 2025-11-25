#include<bits/stdc++.h>
using namespace std;

int n, ret[1002], result;
int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    vector<int> v(5);
    for (int j = 0; j < 5; j++){
      cin >> v[j];
    }
    for (int j = 0; j < 3; j++){
      int a = 0;
      for (int k = j + 1; k < 4; k++){
        for (int l = k + 1; l < 5; l++){
          a = v[j] + v[k] + v[l];
          int b;
          if(a > 9){
            b = a - ((a / 10) * 10);
          }
          else
            b = a;
          
          ret[i] = max(ret[i], b);
        }
      }
    }
    // cout << ret[i] << '\n';
  }
  int diff = ret[1];
  result = 1;
  for (int i = 2; i <= n; i++){
    if(ret[i] >= diff){
      result = i;
      diff = ret[i];
    }
  }
  cout << result;
  return 0;
}