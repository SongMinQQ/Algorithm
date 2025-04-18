#include<bits/stdc++.h>
using namespace std;

int n, pos;
string s;
map<string, int> m;
int main(){
  cin >> n;
  while(n--){
    cin >> s;
    pos = s.find('.');
    m[s.substr(pos + 1, s.size())]++;
  }
  for(auto i : m){
    cout << i.first << ' ' << i.second << '\n';
  }
  return 0;
}