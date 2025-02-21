#include<bits/stdc++.h>
using namespace std;

int maze[102][102], visited[102][102], n, m, y, x;
const int dy[] = {-1, 0, 1 ,0};
const int dx[] = {0, 1, 0, -1};

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%1d",&maze[i][j]);
    }
  }
  visited[0][0] = 1;
  queue<pair<int,int>> q;
  q.push({0,0});
  while(!q.empty()){
    tie(y, x) = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if(visited[ny][nx] == 0 && maze[ny][nx] == 1){
        visited[ny][nx] = visited[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }
  cout << visited[n - 1][m - 1];
  return 0;
}