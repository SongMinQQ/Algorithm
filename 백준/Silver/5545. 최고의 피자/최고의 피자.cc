#include<bits/stdc++.h>
using namespace std;
long long n, a, b, c, ret;
vector<int> v;
int main(){
  cin >> n >> a >> b >> c;
  v.resize(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  ret = c / a;
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; i++){
    c += v[i];
    long long price = a + b * (i + 1);
    ret = max((int)ret, (int)floor(c / price));
  }
  cout << ret;
  return 0;
}