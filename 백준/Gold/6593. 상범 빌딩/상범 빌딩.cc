#include<bits/stdc++.h>
using namespace std;
int l, r, c, visited[32][32][32];
const int dy[] = {-1, 0, 1, 0, 0, 0};
const int dx[] = {0, 1, 0, -1, 0, 0};
const int df[] = {0, 0, 0, 0, 1, -1};
string line;
void bfs(int z, int y, int x, vector<vector<vector<char>>> v){
  visited[z][y][x] = 1;
  queue<tuple<int, int, int>> q;
  q.push({z, y, x});
  int cz, cy, cx;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int cz = get<0>(cur);
    int cy = get<1>(cur);
    int cx = get<2>(cur);
    for (int i = 0; i < 6; i++){
      int nz = cz + df[i];
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c || visited[nz][ny][nx]) continue;
      if(v[nz][ny][nx] == '.' || v[nz][ny][nx] == 'E'){
        q.push({nz, ny, nx});
        visited[nz][ny][nx] = visited[cz][cy][cx] + 1;
      }
    }
  }
}
int main(){
  while(1){
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0) break;
    memset(visited, 0, sizeof(visited));
    vector<vector<vector<char>>> v(l, vector<vector<char>>(r, vector<char>(c)));
    tuple<int, int, int> stIdx, edIdx;
    for (int i = 0; i < l; i++){
      for (int j = 0; j < r; j++){
        cin >> line;
        for (int k = 0; k < c; k++){
          v[i][j][k] = line[k];
          if(line[k] == 'S') stIdx = {i, j, k};
          if(line[k] == 'E') edIdx = {i, j, k};
        }
      }
    }
    int z = get<0>(stIdx);
    int y = get<1>(stIdx);
    int x = get<2>(stIdx);

    int ez = get<0>(edIdx);
    int ey = get<1>(edIdx);
    int ex = get<2>(edIdx);
    bfs(z, y, x, v);
    if(visited[ez][ey][ex] > 0){
      cout << "Escaped in " << visited[ez][ey][ex] - 1 << " minute(s).\n";
    }
    else{
      cout << "Trapped!\n";
    }
  }
  return 0;
}