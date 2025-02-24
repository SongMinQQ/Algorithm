#include<bits/stdc++.h>
using namespace std;

int r, c, visited[52][52], visited2[52][52], y, x, destinationX, destinationY;
char forest[52][52];
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void fillWater(int y, int x){
  visited2[y][x] = 1;
  while(!q2.empty()){
    tie(y,x) = q2.front();
    q2.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited2[ny][nx] || forest[ny][nx] == 'X' || forest[ny][nx] == 'S' || forest[ny][nx] == 'D')continue;
      q2.push({ny,nx});
      visited2[ny][nx] = visited2[y][x] + 1;
    }
  }
}
void move(int y, int x){
  visited[y][x] = 1;
  while(!q1.empty()){
    tie(y,x) = q1.front();
    q1.pop();
    if(visited2[y][x] == visited[y][x]) continue;
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || forest[ny][nx] == 'X')continue;
      // if(visited2[ny][nx] == visited[ny][nx] + 1) continue;
      q1.push({ny,nx});
      visited[ny][nx] = visited[y][x] + 1;
    }
  }
}
int main(){
  cin >> r >> c;
  for(int i = 0 ; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> forest[i][j];
      if(forest[i][j] == 'D'){
        destinationY = i;
        destinationX = j;
      }
      if(forest[i][j] == '*'){
        q2.push({i, j});
      }
      if(forest[i][j] == 'S'){
        q1.push({i, j});
      }
    }
  }
  fillWater(q2.front().first,q2.front().second);
  move(q1.front().first, q1.front().second);
  if(visited[destinationY][destinationX] == 0) cout << "KAKTUS" << '\n';
  else cout << visited[destinationY][destinationX] -1 << '\n';
  return 0;
}