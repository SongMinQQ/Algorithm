#include<bits/stdc++.h>
using namespace std;

int n, m, x, a, b, c, cost, cNode, resultArr[1002], result;
vector <pair<int, int>> v[1004];
vector<int> dists;
int dijkstra(int node){
  int dist[1004];
  fill(&dist[0], &dist[0] + (n+2), 99999999);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, node});
  while(!pq.empty()){
    tie(cost, cNode) = pq.top();
    pq.pop();
    if(cost > dist[cNode]) continue;
    // cout << cost << cNode << '\n';
    for(pair<int,int> i : v[cNode]){
      int nCost = i.second;
      int nNode = i.first;
      if(dist[nNode] > nCost + cost){
        dist[nNode] = nCost + cost;
        pq.push({dist[nNode], nNode});
      }
    }
  }
  if(node == x){
    for (int i = 1; i <= n; i++){
      resultArr[i] = dist[i];
    }
    resultArr[x] = 0;
    return 0;
  }
  
  return dist[x];
}
int main(){
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++){
    cin >> a >> b >> c;
    v[a].push_back({b, c});
  }
  for (int i = 1; i <= n; i++){
    int result = dijkstra(i);
    dists.push_back(result);
  }
  for (int i = 1; i <= n; i++){
    dists[i - 1] += resultArr[i] ;
    result = max(result, dists[i - 1]);
  }
  
  cout << result;
  return 0;
}