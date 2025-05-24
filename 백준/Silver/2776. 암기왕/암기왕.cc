#include<bits/stdc++.h>
using namespace std;

int n, m,num;
int main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);	cout.tie(NULL);
  cin >> n;
  while(n--){
  unordered_map<int, int> mp;
    cin >> m;
  for (int i = 0; i < m; i++){
    cin >> num;
    mp[num] = 1;
  }
  cin >> m;
  while(m--){
    cin >> num;
    mp[num] != 1 ? cout << 0 << '\n' : cout << 1 << '\n';
  }}
  return 0;
}