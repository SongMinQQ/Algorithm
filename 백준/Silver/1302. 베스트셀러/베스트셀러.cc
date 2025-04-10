#include<bits/stdc++.h>
using namespace std;

int n, diff;
string a, result;
map<string, int> m;

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a;
    if(m.find(a) != m.end()){
      m[a]++;
    }
    else m.insert({a, 1});
  }
  
  vector<pair<string, int>> v(m.begin(), m.end());
  sort(v.begin(),v.end());
  for(auto i : v){
    if(i.second > diff){
      result = i.first;
      diff = i.second;
    }
  }
  cout << result << '\n';
  return 0;
}