#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[100003];
int n, m, s, e, t, start, dest, dist[100003], cNode, cCost;
void dijkstra(int node){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  // int cur = 0;
  dist[node] = 0;
  pq.push({node, 0});
  while(!pq.empty()){
    tie(cNode, cCost) = pq.top();
    pq.pop();
    for (pair<int,int> i : v[cNode]){
      int next = i.first, nCost = i.second;
      bool isChange = cCost == nCost ? false : true;
      int nDist = isChange ? dist[cNode] + 1 : dist[cNode];
      if(dist[next] > nDist){
        dist[next] = nDist;
        pq.push({next, nCost});
      }
    }
  }
}
int main(){
  cin >> n >> m;
  fill(&dist[0], &dist[n + 3], 99999999);
  for (int i = 0; i < m; i++){
    cin >> s >> e >> t;
    v[s].push_back({e, t});
    v[e].push_back({s, t});
  }
  cin >> start >> dest;
  dijkstra(start);
  cout << dist[dest] << '\n';
  return 0;
}