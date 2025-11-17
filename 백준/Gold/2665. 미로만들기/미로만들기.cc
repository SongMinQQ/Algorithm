#include<bits/stdc++.h>
using namespace std;

int n;
int a[52][52], dist[52][52];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
void dijkstra(int y, int x){
  dist[y][x] = a[y][x] == 1 ? 0 : 1;
  priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  pq.push({y, x, dist[y][x]});
  int cy, cx, cost;
  while(!pq.empty()){
    tie(cy, cx, cost) = pq.top();
    pq.pop();
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      int nCost;
      nCost = a[ny][nx] == 0 ? 1 : 0;
      if(dist[ny][nx]> nCost + cost){
        dist[ny][nx] = nCost + cost;
        pq.push({ny, nx, dist[ny][nx]});
      }
    }
  }
}
int main(){
  fill(&dist[0][0], &dist[51][51], 99999999);
  cin >> n;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    for (int j = 0; j < line.size(); j++){
      a[i][j] = line[j] - '0';
    }
  }
  dijkstra(0, 0);
  cout << dist[n - 1][n - 1];
  return 0;
}