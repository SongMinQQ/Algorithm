#include<bits/stdc++.h>
using namespace std;

int n, m, x, a, b, c, dist[1002], result;
vector<pair<int,int>> v[1002];

void dijkstra(int s){
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  while(!pq.empty()){
    int cCost, cNode;
    tie(cCost, cNode) = pq.top();
    pq.pop();
    for(pair<int,int> i : v[cNode]){
      int nCost = i.second + cCost;
      int nNode = i.first;
      if(dist[nNode] > nCost){
        dist[nNode] = nCost;
        pq.push({dist[nNode], nNode});
      }
    }
  }
}
int main(){
  cin >> n >> m >> x;
  fill(&dist[0], &dist[1002], 99999999);
  for (int i = 0; i < m; i++){
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  dijkstra(x);
  for (int i = 1; i <= n; i++){
    result = max(result, dist[i]);
  }
  cout << result * 2;
  return 0;

}