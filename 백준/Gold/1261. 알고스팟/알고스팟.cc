#include<bits/stdc++.h>
using namespace std;

int n, m, a[102][102], cnt, y, x, dist[102][102];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0, 0});
  dist[0][0] = 0;
  while(!pq.empty()){
    tie(y, x) = pq.top();
    pq.pop();
    for (int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      int w = (a[ny][nx] == 1 ? 1 : 0);
      int nd = dist[y][x] + w;
      if(dist[ny][nx] > nd){
        dist[ny][nx] = nd;
        pq.push({ny, nx});
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fill(&dist[0][0], &dist[101][102], 99999999);
  cin >> m >> n;
  for (int i = 0; i < n; i++){
    string row;
    cin >> row;
    for (int j = 0; j < m; j++){
      a[i][j] = row[j] - '0';
    }

  }
  dijkstra();
  cout << dist[n - 1][m - 1];
  return 0;
}