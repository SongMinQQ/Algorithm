#include<bits/stdc++.h>
using namespace std;

int n, m, world[502][502], y, x, result, pr, pc, directionResult, visited[502][502];
const char resultDirection[] = {'U', 'R', 'D', 'L'};
const int goDirection[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int bfs(int cy, int cx, int directionNum){
  visited[cy][cx] = 1;
  queue<pair<int,int>> q;
  q.push({cy, cx});
  while (!q.empty()){
    tie(y, x) = q.front();
    q.pop();
    if(visited[y][x] > 10000000)return -1;
    int ny = y + goDirection[directionNum][1];
    int nx = x + goDirection[directionNum][0];
    if(ny < 0 || nx < 0 || ny >= n || nx >= m || world[ny][nx] == 'C'){
      return visited[y][x];
    }
    // if(visited[ny][nx]) return -1;
    if(world[ny][nx] == '\\'){
      if(directionNum == 0) directionNum = 3;
      else if(directionNum == 2) directionNum = 1;
      else directionNum = (directionNum + 1) % 4;
      q.push({ny, nx});
      visited[ny][nx] = visited[y][x] + 1;
    }else if(world[ny][nx] == '/'){
      if(directionNum == 3) directionNum = 2;
      else if(directionNum == 1) directionNum = 0;
      else directionNum = (directionNum + 1) % 4;
      q.push({ny, nx});
      visited[ny][nx] = visited[y][x] + 1;
    }else{
    q.push({ny, nx});
    visited[ny][nx] = visited[y][x] + 1;}
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string line;
    cin >> line;
    for(int j = 0; j < line.size(); j++){
      world[i][j] = line[j];
    }
  }
  cin >> pr >> pc;
  for(int i = 0; i < 4; i++){
    int travelResult = bfs(pr - 1, pc - 1, i);
    if(travelResult > result || travelResult == -1) directionResult = i;
    if(travelResult == -1){result = -1; break;}
    result = max(result, travelResult);
    fill(&visited[0][0], &visited[501][502] , 0);

  }
  if(result == -1){ 
    cout << resultDirection[directionResult] << "\nVoyager" << '\n';
  }
  else{
    cout << resultDirection[directionResult] << '\n' << result << '\n';
  }
  return 0;
}