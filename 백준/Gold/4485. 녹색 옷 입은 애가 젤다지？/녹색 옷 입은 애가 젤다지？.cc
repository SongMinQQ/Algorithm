#include<bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, dist[130][130], num, cy, cx, cost;

void dijkstra(vector<vector<int>> v){
  dist[0][0] = v[0][0];
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  pq.push({v[0][0], {0, 0}});
  while(!pq.empty()){
    auto top = pq.top();
    cost = top.first;
    cy = top.second.first;
    cx = top.second.second;
    pq.pop();
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= n || dist[ny][nx] <= cost) continue;
      int nCost = cost + v[ny][nx];
      if(dist[ny][nx] > nCost){
        dist[ny][nx] = nCost;
        pq.push({nCost,{ny, nx}});
      }
    }
  }
}
int main(){
  int cnt = 1;
  while(1){
    cin >> n;
    fill(&dist[0][0], &dist[n + 1][n + 1], 9999999);
    if(n == 0) break;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> num;
        v[i].push_back(num);
      }
    }
    dijkstra(v);
    cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << '\n';
    cnt++;
  }
  return 0;
}