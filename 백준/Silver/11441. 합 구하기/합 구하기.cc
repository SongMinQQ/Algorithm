#include<bits/stdc++.h>
using namespace std;
int n, m, pre[100006], a, b;
vector<int> A;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  A.resize(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> A[i];
    pre[i] = pre[i - 1] + A[i];
  }
  cin >> m;
  while(m--){
    cin >> a >> b;
    cout << pre[b] - pre[a - 1] << '\n';
  }
  return 0;
}