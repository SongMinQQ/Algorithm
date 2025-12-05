#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> v;
int main(){
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  ll diff = v[0] + v[1] + v[v.size() - 1];
  vector<ll> ret;

  for (int i = 0; i < n - 2; i++){
    int idx1 = i + 1, idx2 = n - 1;
    while (idx1 < idx2){
      ll s = v[i] + v[idx1] + v[idx2];
      if (llabs(s) < llabs(diff)){
        diff = s;
        ret = {v[idx1], v[idx2], v[i]};
      }
      if (s > 0)
        idx2--;
      else if(s < 0)
        idx1++;
      else{
        cout << v[i] << ' ' << v[idx1] << ' ' << v[idx2];
        return 0;
      }
    }
  }
    
  sort(ret.begin(), ret.end());
  for(ll i : ret){
    cout << i << ' ';
  }
  return 0;
}