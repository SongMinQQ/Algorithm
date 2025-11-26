#include<bits/stdc++.h>
using namespace std;

int n, g, ret;
vector<int> v, prefix;

int main(){
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  cin >> g;
  int num = 0, idx = 0;
  for (int i = 0; i < g; i++){
    num += v[i];
  }
  prefix.push_back(num);
  for (int i = g; i < n; i++){
    num += v[i];
    num -= v[idx];
    prefix.push_back(num);
    idx++;
  }
  n = prefix.size();
  vector<int> dp1(n), dp2(n), dp3(n);
  dp1[0] = prefix[0];
  for (int i = 1; i < n; i++){
    dp1[i] = max(dp1[i - 1], prefix[i]);
  }
  for (int i = 0; i < n; i++){
    if(i < g) dp2[i] = 0;
    else{
      dp2[i] = max(dp2[i - 1], prefix[i] + dp1[i - g]);
    }
  }
  for (int i = 0; i < n; i++){
    if(i < g * 2) dp3[i] = 0;
    else{
    dp3[i] = max(dp3[i - 1], prefix[i] + dp2[i - g]);}
  }
    cout << dp3[n - 1];
  return 0;
}