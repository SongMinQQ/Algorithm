#include<bits/stdc++.h>
using namespace std;

int v, e, k, a, b, c, dist[20002];
vector<pair<int,int>> ve[20002];
void dijkstra(){
  dist[k] = 0;
  priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, k});
  while(!pq.empty()){
    int cCost, cNode;
    tie(cCost, cNode) = pq.top();
    pq.pop();
    for(pair<int, int> i : ve[cNode]){
      int nCost = i.second, nNode = i.first;
      if(dist[nNode] > cCost + nCost){
        dist[nNode] = cCost + nCost;
        pq.push({dist[nNode], nNode});
      }
    }
  }
}
int main(){
  cin >> v >> e >> k;
  fill(&dist[0], &dist[20002], 99999999);
  for (int i = 0; i < e; i++){
    cin >> a >> b >> c;
    ve[a].push_back({b, c});
  }
  dijkstra();
  for (int i = 1; i <= v; i++){
    dist[i] != 99999999 ? cout << dist[i] << '\n' : cout << "INF\n";
  }
  return 0;
}