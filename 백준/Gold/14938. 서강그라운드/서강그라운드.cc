#include<bits/stdc++.h>
using namespace std;
const int INF = 99999999;
int n, m, r, num, dist[103], result;
vector<int> t;
bool visited[102];
vector<pair<int, int>> v[102];
int getResult(){
  int sum = 0;
  for (int i = 1; i <= n; i++){
    if(dist[i] <= m && dist[i] != INF) sum+= t[i - 1];
  }
  return sum;
}
void dijkstra(int node){
  priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> PQ;
  PQ.push(make_pair(0, node));
  dist[node] = 0;
  while (!PQ.empty()){
    int cost = PQ.top().first;
    int cur = PQ.top().second;
    PQ.pop();
    for(int i = 0; i < v[cur].size(); i++){ 
      int next = v[cur][i].first; 
      int nCost = v[cur][i].second; 
      if (dist[next] > cost + nCost){ 
        dist[next] = cost + nCost; 
        PQ.push({dist[next], next}); 
      } 
    }
  }
}
int main(){
  cin >> n >> m >> r;
  fill(&dist[0], &dist[n + 1], INF);
  for (int i = 0; i < n; i++){
    cin >> num;
    t.push_back(num);
  }
  for (int i = 0; i < r; i++){
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  for (int i = 1; i <= n; i++){
    dijkstra(i);
    result = max(result, getResult());
    // cout << "i : " << i << " dist[5] : " << dist[5] << '\n';
    fill(&dist[0], &dist[n + 1], INF);
  }
  cout << result;
  return 0;
}