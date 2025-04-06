#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[50002];
int dist[50002], n, m, a, b, c, cost, node;
void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  while(!pq.empty()){
    tie(cost, node) = pq.top();
    pq.pop();
    for (int i = 0; i < v[node].size(); i++){
      int nCost = v[node][i].second;
      int next = v[node][i].first;
      if(dist[next] > cost + nCost){
        dist[next] = cost + nCost;
        pq.push({dist[next], next});
      }
    }
  }
}
int main(){
  cin >> n >> m;
  fill(&dist[0], &dist[n + 2], 99999999);
  for (int i = 0; i < m; i++){
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  dijkstra();
  cout << dist[n] << '\n';
  return 0;
}