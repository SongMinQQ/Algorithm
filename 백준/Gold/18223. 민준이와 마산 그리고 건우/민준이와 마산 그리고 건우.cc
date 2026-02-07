#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int v, e, p, a, b, c, dist[5002];
vector<vector<pair<int, int>>> g;
void dijkstra(int s){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[s] = 0;
  pq.push({s, 0});
  int cost, node;
  while(!pq.empty()){
    tie(node, cost) = pq.top();
    pq.pop();
    for(auto i : g[node]){
      int nNode = i.first, nCost = i.second;
      if(dist[nNode] > cost + nCost){
        dist[nNode] = cost + nCost;
        pq.push({nNode, dist[nNode]});
      }
    }
  }
}
int main(){
  cin >> v >> e >> p;
  g.resize(v + 1);
  for (int i = 0; i < e; i++){
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  fill(&dist[0], &dist[5002], INF);
  dijkstra(p);
  int firstRet = dist[1] + dist[v];
  fill(&dist[0], &dist[5002], INF);
  dijkstra(1);
  int secondRet = dist[v];
  // cout << firstRet << " " << secondRet << "\n";
  firstRet == secondRet ? cout << "SAVE HIM" : cout << "GOOD BYE";
  return 0;
}