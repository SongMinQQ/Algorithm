#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[1002];
int n, m, sNum, dNum, a, b, c, dist[1002], cost, cur;

void dijkstra(int node){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, node});
  dist[node] = 0;
  while(!pq.empty()){
    tie(cost, cur) = pq.top();
    // cout << "cost : " << cost << " cur : " << cur << '\n';
    pq.pop();
    if(cost > dist[cur]) continue;
    for(int i = 0; i < v[cur].size(); i++){
      int next = v[cur][i].first;
      int nCost = v[cur][i].second;
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
    // v[b].push_back({a, c});
  }
  cin >> sNum >> dNum;
  dijkstra(sNum);
  cout << dist[dNum] << '\n';
  return 0;
}