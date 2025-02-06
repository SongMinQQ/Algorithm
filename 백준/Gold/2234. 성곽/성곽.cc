#include<bits/stdc++.h>
using namespace std;

int castle[52][52],visited[52][52],visited2[52][52],visited3[52][52],n,m,rooms,big = 0,biggest,y, x, roomSizes[2502], sepRoom;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

void show(){
  cout << '\n' << '\n';
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << visited[i][j] << ' ';
    }
    cout << '\n';
  }
}

void show2(){
  cout << '\n' << '\n';
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << visited2[i][j] << ' ';
    }
    cout << '\n';
  }
}
int bfs(int cy, int cx){
  int area = 1;
  visited[cy][cx] = 1;
  // cout << "bfs call " << cy << ' ' << cx <<'\n' ;
  queue<pair<int,int>> q;
  q.push({cy,cx});
  while (!q.empty())
  {
    tie(y,x) = q.front();
    // cout << castle[y][x] <<  " call\n";

    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] != 0) continue;
      if(castle[y][x] & (1 << i))continue;
      visited[ny][nx] =  1;
      // big = max(visited[ny][nx] ,big);
      area++;
      q.push({ny, nx});
    }
  }
  return area;
}

int bfs2(int cy, int cx, int roomNum){
  int area = 1;
  visited2[cy][cx] = roomNum;
  // cout << "bfs call " << cy << ' ' << cx <<'\n' ;
  queue<pair<int,int>> q;
  q.push({cy,cx});
  while (!q.empty())
  {
    tie(y,x) = q.front();
    // cout << castle[y][x] <<  " call\n";

    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited2[ny][nx] != 0) continue;
      if(castle[y][x] & (1 << i))continue;
      visited2[ny][nx] =  roomNum;
      // big = max(visited[ny][nx] ,big);
      area++;
      q.push({ny, nx});
    }
  }
  return area;
}

void bfs3(int cy, int cx){
  visited3[cy][cx] = 1;
  // cout << "bfs call " << cy << ' ' << cx <<'\n' ;
  queue<pair<int,int>> q;
  q.push({cy,cx});
  while (!q.empty())
  {
    tie(y,x) = q.front();
    // cout << castle[y][x] <<  " call\n";

    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited3[ny][nx] != 0) continue;
      if(castle[y][x] & (1 << i)){
        // cout << '\n' << "neighborindex" << y << x << ' ' << ny << nx << '\n';
        if (visited2[y][x] != visited2[ny][nx]){
        biggest = max(roomSizes[visited2[y][x]] + roomSizes[visited2[ny][nx]], biggest);
        continue;}
        else continue;
      }
      visited3[ny][nx] =  1;
      // big = max(visited[ny][nx] ,big);
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
        // show();
      }
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(visited2[i][j] == 0){
        sepRoom = bfs2(i,j,roomNumber);
        // big = max(bfs(i, j),big);
        roomSizes[roomNumber] = sepRoom;
        roomNumber++;

        // show2();
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

  // for(int i = 1; i < rooms + 1; i++){
  //   cout << roomSizes[i] << '\n';
  // }
  // cout << '\n';
  
  cout << rooms << '\n' << big << '\n' << biggest;
  /* BFS 쓸듯
  가장 넓은 방크기 어케구함?
  visited에 방 번호를 부여
  방 번호 index에 해당하는 넓이를 저장하는 배열 변수 - 여기까지 했음
  방이 이웃하는지 확인
  방 번호에 해당하는 index끼리 더함
   */
  return 0;
}