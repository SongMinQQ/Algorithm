#include<bits/stdc++.h>
using namespace std;

int n, m, s, d, dist[502], u, v, p;
vector<vector<int>> prevNode;

void removeGraph(){

}
void dijkstra(int s, const vector<vector<pair<int,int>>>& ve) {
  const int INF = 1e9;
  fill(dist, dist + 502, INF);
  prevNode.assign(n, {});
  dist[s] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    int cCost, cNode;
    tie(cCost, cNode) = pq.top();
    pq.pop();
    if (cCost > dist[cNode]) continue;
    for (auto edge : ve[cNode]) {
      int nNode = edge.first;
      int w     = edge.second;
      int nCost = cCost + w;
      if (dist[nNode] > nCost) {
        dist[nNode] = nCost;
        prevNode[nNode].clear();
        prevNode[nNode].push_back(cNode);
        pq.push({nCost, nNode});
      }
      else if (dist[nNode] == nCost) {
        prevNode[nNode].push_back(cNode);
      }
    }
  }
}
void removeGraph(vector<vector<pair<int,int>>>& ve) {
  queue<int> q;
  vector<int> visited(n, 0);
  q.push(d);
  visited[d] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int prev : prevNode[cur]) {
      auto &adj = ve[prev];
      adj.erase(
        remove_if(adj.begin(), adj.end(),
          [&](const pair<int,int>& e) {
            return e.first == cur;
          }),
        adj.end()
      );
      if (!visited[prev]) {
        visited[prev] = 1;
        q.push(prev);
      }
    }
  }
}
int main(){
  while(1){
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    vector<vector<pair<int,int>>> ve(n);
    cin >> s >> d;
    for (int i = 0; i < m; i++){
      cin >> u >> v >> p;
      ve[u].push_back({v, p});
    }
    dijkstra(s, ve);
    int shortest = dist[d];
    if (shortest == 1e9) {
      cout << -1 << '\n';
      continue;
    }
    removeGraph(ve);
    dijkstra(s, ve);
    int almost = dist[d];

    if (almost == 1e9) cout << -1 << '\n';
    else cout << almost << '\n';
  }
  return 0;
}
