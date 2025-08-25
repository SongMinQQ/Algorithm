#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 999999999;
vector<pair<int, int>> v[802];
int n, e, a, b, c, dist[802], result, v1, v2;
void dijkstra(int s){
  fill(&dist[0], &dist[802], INF);
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  while(!pq.empty()){
    int cCost, cNode;
    tie(cCost, cNode) = pq.top();
    pq.pop();
    for(pair<int,int> i : v[cNode]){
      int nCost = cCost + i.second, nNode = i.first;
      if(dist[nNode] > nCost){
        dist[nNode] = nCost;
        pq.push({nCost, nNode});
      }
    }
  }
}
int main(){
  cin >> n >> e;
  for (int i = 0; i < e; i++){
    cin >> a >> b >> c;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
  }
  cin >> v1 >> v2;
  dijkstra(1);
  int d1_v1 = dist[v1];
  int d1_v2 = dist[v2];

  dijkstra(v1);
  int dv1_v2 = dist[v2];
  int dv1_n  = dist[n];

  dijkstra(v2);
  int dv2_v1 = dist[v1];
  int dv2_n  = dist[n];

  int route1 = (d1_v1>=INF || dv1_v2>=INF || dv2_n>=INF) ? INF : d1_v1 + dv1_v2 + dv2_n;
  int route2 = (d1_v2>=INF || dv2_v1>=INF || dv1_n>=INF) ? INF : d1_v2 + dv2_v1 + dv1_n;

  int ans = min(route1, route2);
  cout << (ans >= INF ? -1 : ans) << '\n';
  return 0;
}