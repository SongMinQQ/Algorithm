#include<bits/stdc++.h>
using namespace std;

string line;
char m[10][10];
bool visited[10][10];
vector<pair<int,int>> walls;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int cnt;
void move(){
  if(cnt >= 8) return;
  fill(&visited[0][0], &visited[7][8], 0);
  for (int i = 0; i < walls.size(); i++){
    if(walls[i].first >= 8) continue;
    else{
      m[walls[i].first][walls[i].second] = '.';
    }
  }
  for (int i = 0; i < walls.size(); i++){
    walls[i].first++;
    if(walls[i].first >= 8) continue;
    m[walls[i].first][walls[i].second] = '#';
  }
}
int main(){
  for (int i = 0; i < 8; i++){
    cin >> line;
    for (int j = 0; j < line.size(); j++){
      m[i][j] = line[j];
      if(line[j] == '#') walls.push_back({i, j});
    }
  }
  // 시작인덱스 7, 0 목적지 0, 7
  queue<pair<int, int>> q;
  q.push({7, 0});
  int y, x;
  visited[7][0] = 1;
  while(!q.empty()){
    int time = q.size();
    while(time--){
      tie(y, x) = q.front();
      q.pop();
      if(m[y][x] == '#') continue;
      if(y == 0 && x == 7){
        cout << 1;
        return 0;
      }
      for (int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= 8 || nx >= 8 || visited[ny][nx] || m[ny][nx] == '#') continue;
        visited[ny][nx] = 1;
        q.push({ny, nx});
      }
      // if(!visited[y][x]){
        if(m[y][x] != '#')
        q.push({y, x});
      // }
    }
    cnt++;
    move();
    
  }
  cout << 0;
  return 0;
}