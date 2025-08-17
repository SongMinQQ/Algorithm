#include<bits/stdc++.h>
using namespace std;

int w, h;
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool visited[50][50];

void bfs(vector<vector<int>>& v, int y, int x){
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});
  while(!q.empty()){
    int cy, cx;
    tie(cy, cx) = q.front();
    q.pop();
    for (int i = 0; i < 8; i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny < 0 || nx < 0 || ny >= h || nx >= w || visited[ny][nx] || v[ny][nx] == 0) continue;
      q.push({ny, nx});
      visited[ny][nx] = 1;
    }
  }
}
int main() {
  while(1){
    cin >> w >> h;
    int result = 0;
    if(w == 0 && h == 0)
      break;
    vector<vector<int>> v(h, vector<int>(w));
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        cin >> v[i][j];
      }
    }
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        if(v[i][j] == 1 && visited[i][j] == 0){ 
          bfs(v, i, j);
          result++;
        }
      }
    }
    cout << result << '\n';
    fill(&visited[0][0], &visited[0][0] + 50*50, 0);
  }
  return 0;
}