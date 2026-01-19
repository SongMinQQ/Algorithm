#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<ll> v;
int main(){
  cin >> n >> m;
  ll a;
  for (int i = 0; i < n; i++){
    cin >> a;
    v.push_back(a);
  }
  ll s = 0, ret = 0;
  int l = 0;

  for (int r = 0; r < n; r++) {
    s += v[r];
    while (l <= r && s > m) {
      s -= v[l];
      l++;
    }
    ret = max(ret, s);
  }

  cout << ret;
  return 0;
}