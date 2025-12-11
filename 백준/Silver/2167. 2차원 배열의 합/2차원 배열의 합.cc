#include<bits/stdc++.h>
using namespace std;

int n, m, a[302][302], k, q, w, e, r;
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  cin >> k;
  while(k--){
    long long ret = 0;
    cin >> q >> w >> e >> r;
    q--;
    w--;
    e--;
    r--;
    for (int i = q; i <= e; i++){
      for (int j = w; j <= r; j++){
        ret += a[i][j];
      }
    }
    cout << ret << '\n';
  }
  return 0;
}