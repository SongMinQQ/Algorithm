#include<bits/stdc++.h>
using namespace std;

int n, m, a;
vector<int> v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  while(n--){
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  cout << v[m-1];
  return 0;
}