#include<bits/stdc++.h>
using namespace std;

int visited[21][21], r, c, result, board[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
//메모이제이션으로 풀어보자

void dfs(int y, int x, int cnt, int num){
  result = max(result, cnt);
  //이미 방문한 곳이면 그냥 끝냄
  if(visited[y][x] == num) return;
  visited[y][x] = num;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
    //다음에 방문할 곳이 이미 방문한적이 있다면 넘김
    if(num & (1 << board[ny][nx])) continue;
    //근데 |= 과 | 의 차이는?
    dfs(ny, nx, cnt + 1, num | (1 << board[ny][nx]));
  }
}
int main(){
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    string line;
    cin >> line;
    for(int j = 0; j < c; j++){
      board[i][j] = (int)line[j] - 'A';
    }
  }
  dfs(0, 0, 1, (1 << board[0][0]));
  cout << result << '\n';
  return 0;
}