#include<bits/stdc++.h>
using namespace std;

map<string, bool> mp;
string a, b;
int n, cnt;
int main(){
  cin >> n;
  while(n--){
    cin >> a >> b;
    if(a == "ChongChong" || b == "ChongChong"){
      mp[a] = true;
      mp[b] = true;
      continue;
    }
    if(mp[a] == true || mp[b] == true){
      mp[a] = true;
      mp[b] = true;
    }
    else {
      mp[a] = false;
      mp[b] = false;
    }
  }
  for(auto i : mp){
    if(i.second == true)
      cnt++;
  }
  cout << cnt;
  return 0;
}