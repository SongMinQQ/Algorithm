#include<bits/stdc++.h>
using namespace std;

int dist[10002], t, n, d, c, q, w, e, cCost, cNode;

void dijkstra(vector<vector<pair<int,int>>> ve, int s){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[s] = 0;
  pq.push({0, s});
  while(!pq.empty()){
    tie(cCost, cNode) = pq.top();
    pq.pop();
    for(pair<int,int> i : ve[cNode]){
      int nCost = cCost + i.second;
      int next = i.first;
      if(dist[next] > nCost){
        dist[next] = nCost;
        pq.push({dist[next], next});
      }
    }
  }
}
int main(){
  cin >> t;
  while(t--){
    int result = 0, cnt = 0;
    cin >> n >> d >> c;
    fill(&dist[0], &dist[n + 2], 9999999);
    vector<vector<pair<int, int>>> v(n + 1);
    while(d--){
      cin >> q >> w >> e;
      v[w].push_back({q, e});
    }
    dijkstra(v, c);
    for (int i = 1; i <= n; i++){
      if(dist[i] != 9999999){
        cnt++;
        result = max(dist[i], result);
      }
    }
    cout << cnt << ' ' << result << '\n';
  }
  return 0;
}