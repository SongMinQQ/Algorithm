#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
int n, m;
string s;
bool cmp(const pair<string,int> &a, const pair<string,int> &b) {
  if (a.second != b.second)
    return a.second > b.second;
  else if(a.first.size() != b.first.size())
    return a.first.size() > b.first.size();
  else return a.first < b.first;
};

int main(){
  cin >> n >> m;
  while(n--){
    cin >> s;
    if(s.size() >= m)
      mp[s]++;
  }
  vector<pair<string, int>> v(mp.begin(), mp.end());
  sort(v.begin(),v.end(), cmp);
  for(auto i : v){
    cout << i.first << '\n';
  }
  return 0;
}