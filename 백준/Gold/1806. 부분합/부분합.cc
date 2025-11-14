#include<bits/stdc++.h>
using namespace std;

int n, s, ret = INT_MAX;
int main(){
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  int p1 = 0, p2 = 1, a = v[0] + v[1];
  if(v[0] >= s){
    cout << 1;
    return 0;
  }
  while(p2 <= n){
    if(a >= s){
      ret = min(ret, (p2 - p1) + 1);
      a -= v[p1];
      p1++;
    }
    else{
      p2++;
      if(p2 == n) break;
      a+=v[p2];
    }
  }
  ret==INT_MAX ? cout << 0 : cout << ret;
  return 0;
}