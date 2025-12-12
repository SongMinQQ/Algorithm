#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v, e, a, b, c, arr[1000002], ret;
void make(){
  for (int i = 1; i <= v; i++){
    arr[i] = i;
  }
}
int find(ll a){
  if(arr[a] == a) return a;
  return arr[a] = find(arr[a]);
}
bool makeUnion(ll a, ll b){
  ll aRoot = find(a);
  ll bRoot = find(b);
  if(aRoot == bRoot) return false;
  arr[aRoot] = bRoot;
  return true;
}

bool isSame(ll a, ll b){
  ll q = find(a);
  ll w = find(b);
  if(q == w)return true;
  else return false;
}
int main(){
  cin >> v >> e;
  vector<pair<ll, pair<ll,ll>>> ve;
  for (int i = 0; i < e; i++){
    cin >> a >> b >> c;
    ve.push_back({c, {a, b}});
  }
  make();
  sort(ve.begin(), ve.end());
  for (int i = 0; i < ve.size(); i++){
    if(!isSame(ve[i].second.first, ve[i].second.second)){
      makeUnion(ve[i].second.first, ve[i].second.second);
      ret += ve[i].first;
    }
  }
  cout << ret;
  return 0;
}