#include<bits/stdc++.h>
using namespace std;
int n, s, t, result;
vector<pair<int, int>> v;
set<int> se;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s >> t;
    v.push_back({s, t});
  }
  sort(v.begin(),v.end());
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  for(pair<int, int> i : v){
    // if(pq.size()) cout << pq.top().first << ' ' << pq.top().second << '\n';
    if(pq.empty() || pq.top().first > i.first){
      pq.push({i.second, i.first});
      result++;
    }
    else if(pq.top().first <= i.first){
      pq.push({i.second, i.first});
      pq.pop();
    }
  }
  cout << result << '\n';
  return 0;
}