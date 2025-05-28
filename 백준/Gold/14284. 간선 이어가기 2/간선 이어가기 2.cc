#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, c, dist[5002], s, t;
vector<pair<int,int>> v[5002];
void dijkstra(){
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({s, 0});
  while(!pq.empty()){
    int cNode = pq.top().first, cCost = pq.top().second;
    pq.pop();
    for(pair<int,int> i : v[cNode]){
      int nCost = i.second + cCost, nNode = i.first;
      if(dist[nNode] > nCost){
        dist[nNode] = nCost;
        pq.push({nNode, dist[nNode]});
      }
    }
  }
}
int main(){
  cin >> n >> m;
  fill(&dist[0], &dist[5002], 999999999);
  for (int i = 0; i < m; i++){
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  cin >> s >> t;
  dijkstra();
  cout << dist[t];
  return 0;
}