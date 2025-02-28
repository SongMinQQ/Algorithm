#include<bits/stdc++.h>
using namespace std;

int n, visited1[1010][1010], visited2[1010][1010], y, x, w, h;
char m[1010][1010];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int bfs1(queue<pair<int, int>> q, queue<pair<int, int>> q2){
  while(!q.empty()){
    if(q2.size()){
      int size = q2.size();
      for(int j = 0; j < size; j++){
      tie(y, x) = q2.front();
      q2.pop();
        for(int i = 0; i < 4; i++){
          int ny = y + dy[i];
          int nx = x + dx[i];
          if(ny < 0 || nx < 0 || ny >= h || nx >= w || m[ny][nx] != '.' /*|| visited1[ny][nx]*/ || m[ny][nx] == 0) continue;
          // visited1[ny][nx] = visited1[y][x] + 1;
          q2.push({ny, nx});
          m[ny][nx] = '*';
        }
      }
    }
    int size2 = q.size();
    for(int j = 0; j < size2; j++){
      tie(y, x) = q.front();
      q.pop();
      for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(m[ny][nx] == '#' || m[ny][nx] == '*' || visited2[ny][nx]) continue;
        if(ny < 0 || nx < 0 || ny >= h || nx >= w) return visited2[y][x];
        visited2[ny][nx] = visited2[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }
  return 0;
}

int main(){
  cin >> n;
  while(n--){
    int result = 0;
    cin >> w >> h;
    queue<pair<int, int>> fire, sang;
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        cin >> m[i][j];
        if(m[i][j] == '*') {
          visited1[i][j] = 1;
          fire.push({i,j});
        }
        if(m[i][j] == '@') {
          visited2[i][j] = 1;
          sang.push({i,j});
        }
      }
    }
    result = bfs1(sang, fire);
    if(result == 0) cout << "IMPOSSIBLE\n";
    else cout << result << '\n';
    // fill(&visited1[0][0], &visited1[h + 1][w + 1], 0);
    fill(&visited2[0][0], &visited2[h + 1][w + 1], 0);
    fill(&m[0][0], &m[h + 1][w + 1], 0);
  }
  //날먹 안됨 예외있음 정석으로 풀어야함~
  return 0;
}