#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, s, b;
vector<pair<ll,ll>> v;
vector<vector<int>> combination;
ll result = 9999999999;

void combi(int s, vector<int> v, int size){
  if(v.size() == size){
    combination.push_back(v);
    return;
  }
  for(int i = s; i < n; i++){
    v.push_back(i);
    combi(i + 1, v, size);
    v.pop_back();
  }
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s >> b;
    v.push_back({s, b});
  }
  vector<int> vect;
  for(int i = 0; i < n; i++) {
    combi(0, vect, i + 1);
  }
  for(vector<int> i : combination){
    ll sour = 1, bitter = 0;
    for(int j : i){
      sour *= v[j].first;
      bitter += v[j].second;
    }
    ll diff = abs(sour - bitter);
    result = min(result, diff);
  }
  cout << result << '\n';
  return 0;
}