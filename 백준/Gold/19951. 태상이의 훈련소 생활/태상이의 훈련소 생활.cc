#include<bits/stdc++.h>
using namespace std;

int n, m, num, a, b;
vector<int> v, d;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  v.resize(n + 2);
  d.resize(n + 2);
  for (int i = 1; i <= n; i++){
    cin >> v[i];
    // d[i] = v[i];
  }
  while(m--){
    cin >> a >> b >> num;
    d[a] += num;
    d[b + 1] -= num;
  }
  for (int i = 1; i <= n; i++){
    d[i] += d[i - 1];
    cout << v[i] + d[i] << ' ';
  }
  return 0;
}