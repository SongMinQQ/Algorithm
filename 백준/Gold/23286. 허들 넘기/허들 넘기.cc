#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 99999999999;
int n, m, t, u, v, h, a, b, cCost, cur;
vector<pair<int, int>> graph[302];
vector<vector<ll>> result(302, vector<ll>(302, inf));
void dijkstra(int node){
  vector<ll> dist(n + 1, inf);
  dist[node] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, node});
  while(!pq.empty()){
    tie(cCost, cur) = pq.top();
    pq.pop();
    if(cCost > dist[cur]) continue;
    for(pair<int,int> i : graph[cur]){
      int nCost = i.second, next = i.first;
      int newCost = max(cCost, nCost);
      
      if(dist[next] > newCost){
        dist[next] = newCost;
        pq.push({dist[next], next});
      }
    }
  }
  for (int i = 1; i <= n; i++){
    result[node][i] = dist[i];
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> t;
  for (int i = 0; i < m; i++){
    cin >> u >> v >> h;
    graph[u].push_back({v, h});
  }
  for (int i = 1; i <= n; i++){
    dijkstra(i);
  }
  while(t--){
    cin >> a >> b;
    cout << (result[a][b] == inf ? -1 : result[a][b]) << "\n";
  }
  return 0;
}