#include<bits/stdc++.h>
using namespace std;

int castle[52][52],visited[52][52],visited2[52][52],visited3[52][52],n,m,rooms,big = 0,biggest,y, x, roomSizes[2502], sepRoom;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

int bfs(int cy, int cx){
  int area = 1;
  visited[cy][cx] = 1;
  queue<pair<int,int>> q;
  q.push({cy,cx});
  while (!q.empty())
  {
    tie(y,x) = q.front();

    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] != 0) continue;
      if(castle[y][x] & (1 << i))continue;
      visited[ny][nx] =  1;
      area++;
      q.push({ny, nx});
    }
  }
  return area;
}

int bfs2(int cy, int cx, int roomNum){
  int area = 1;
  visited2[cy][cx] = roomNum;
  queue<pair<int,int>> q;
  q.push({cy,cx});
  while (!q.empty())
  {
    tie(y,x) = q.front();

    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited2[ny][nx] != 0) continue;
      if(castle[y][x] & (1 << i))continue;
      visited2[ny][nx] =  roomNum;
      area++;
      q.push({ny, nx});
    }
  }
  return area;
}

void bfs3(int cy, int cx){
  visited3[cy][cx] = 1;
  queue<pair<int,int>> q;
  q.push({cy,cx});
  while (!q.empty())
  {
    tie(y,x) = q.front();

    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited3[ny][nx] != 0) continue;
      if(castle[y][x] & (1 << i)){
        if (visited2[y][x] != visited2[ny][nx]){
        biggest = max(roomSizes[visited2[y][x]] + roomSizes[visited2[ny][nx]], biggest);
        continue;}
        else continue;
      }
      visited3[ny][nx] =  1;
      q.push({ny, nx});
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> castle[i][j];
    }
  }
  int roomNumber = 1;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(visited[i][j] == 0){
        rooms++;
        big = max(bfs(i, j),big);
      }
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(visited2[i][j] == 0){
        sepRoom = bfs2(i,j,roomNumber);
        roomSizes[roomNumber] = sepRoom;
        roomNumber++;

      }
    }
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(visited3[i][j] == 0){
        bfs3(i,j);
      }
    }
  }

  cout << rooms << '\n' << big << '\n' << biggest;
  return 0;
}