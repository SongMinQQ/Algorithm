#include <bits/stdc++.h>
using namespace std;

int n, k, result;
int main(){
  cin >> n >> k;
  vector<int> v(n), v2;
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  for (int i = 0; i < n - 1; i++){
    if(v[i] == v[i + 1]) continue;
    v2.push_back(v[i + 1] - v[i]);
  }
  sort(v2.begin(), v2.end());
  k--;
  for (int i = 0; i < (int)v2.size() - k; i++){
    result += v2[i];
  }
  cout << result;
  return 0;
}