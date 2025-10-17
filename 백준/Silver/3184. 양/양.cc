#include<bits/stdc++.h>
using namespace std;

char ma[253][253];
bool visited[253][253];
int n, m, ret1, ret2;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool check(char a){
  if(a == '.' || a == 'o' || a == 'v')
    return true;
  return false;
}
void bfs(int y, int x){
  int cy, cx, yang = 0, nek = 0;
  queue<pair<int, int>> q;
  q.push({y, x});
  while(!q.empty()){
    tie(cy, cx) = q.front();
    q.pop();
    if(ma[cy][cx] == 'o') yang++;
    if(ma[cy][cx] == 'v') nek++;
    for (int i = 0; i < 4; i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || ma[ny][nx] == '#')continue;
      if(!visited[ny][nx]){
        visited[ny][nx] = 1;
        q.push({ny, nx});
      }
    }
  }
  yang > nek ? ret1 += yang : ret2 += nek;
  return;
}
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    for (int j = 0; j < line.size(); j++){
      ma[i][j] = line[j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(check(ma[i][j]) && !visited[i][j]){
        visited[i][j] = 1;
        bfs(i, j);
      }
    }
  }
  cout << ret1 << '\n' << ret2;
  return 0;
}