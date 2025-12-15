#include<bits/stdc++.h>
using namespace std;

int n, ret;
vector<int> v;
int main(){
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  for (int i = n - 1; i > 0; i--){
    if(v[i - 1] >= v[i]){
      ret += v[i - 1] - v[i] + 1;
      v[i - 1] = v[i] - 1;
    }
  }
  cout << ret;
  return 0;
}