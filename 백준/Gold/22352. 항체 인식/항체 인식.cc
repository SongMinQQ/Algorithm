#include<bits/stdc++.h>
using namespace std;

int before[32][32], after[32][32], y, x, n, m, cnt;
int visited[32][32], visited2[32][32];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int cy, int cx, int num){
  queue<pair<int,int>> q;
  q.push({cy,cx});
  while(!q.empty()){
    tie(y, x) = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m ||(before[ny][nx] != before[y][x])||visited[ny][nx]) continue;
      q.push({ny,nx});
      visited[ny][nx] = visited[y][x] + 1;
      if(after[ny][nx] != num) cnt++;
    }
  }
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> before[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> after[i][j];
    }
  }
  int checkCnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!visited[i][j]){
        visited[i][j] = 1;
        bfs(i,j,after[i][j]);
        if(after[i][j] != before[i][j]) checkCnt++;
      }
    }
  }
  

  (cnt > 0 || checkCnt > 1) ? cout << "NO\n" : cout << "YES\n";
  return 0;
}