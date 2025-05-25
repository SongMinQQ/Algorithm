#include<bits/stdc++.h>
using namespace std;

int n, m, k, x, dist[300002], a, b, cnt;
vector<int> v[300002];
void dijkstra(int s){
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  while(!pq.empty()){
    int cCost, cNode;
    tie(cCost, cNode) = pq.top();
    pq.pop();
    for(int i : v[cNode]){
      int nCost = cCost + 1;
      if(dist[i] > nCost){
        dist[i] = nCost;
        pq.push({dist[i], i});
      }
    }
  }
}
int main(){
  cin >> n >> m >> k >> x;
  fill(&dist[0], &dist[300002], 99999999);
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    v[a].push_back(b);
  }
  dijkstra(x);
  for (int i = 1; i <= n; i++){
    if(dist[i] == k){
      cout << i << '\n';
      cnt++;
    }
  }
  if(cnt == 0)
    cout << -1;
  return 0;
}