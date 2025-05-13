#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n, a, b, c, result;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a >> b >> c;
    v.push_back({b, c});
  }
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for(pair<int,int> i : v){
    if(!pq.empty() && i.first >= pq.top()){
      pq.pop();
      pq.push(i.second);
    }
    else pq.push(i.second);
    result = max(result, (int)pq.size());
  }
  cout << result;
  return 0;
}