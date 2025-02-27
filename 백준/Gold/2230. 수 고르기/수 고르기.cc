#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll result =2e9;
int main(){
  cin >> n >> m;
  vector<ll> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  int idx1 = 0, idx2 = 0;
  while(idx1 < n){
    ll sum = abs(v[idx1] - v[idx2]);
    if(sum >= m && idx2 < n){
      result = min(sum, result);
      idx2++;
    }
    else {
      idx1++;
    }
  }
  if(n == 1) cout << m << '\n';
  else cout << result << '\n';
  return 0;
}