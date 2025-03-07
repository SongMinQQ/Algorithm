#include<bits/stdc++.h>
using namespace std;

deque<pair<int,int>> snake;
int n, k, l, m[102][102], a, b, y, x, changeT, changeD;
bool visited[102][102] = {0};
char c;
queue<pair<int, char>> direction; 
const int nxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(){
  cin >> n;
  cin >> k;
  while(k--){
    cin >> a >> b;
    m[a-1][b-1] = 1;
  }
  cin >> l;
  while(l--){
    cin >> a >> c;
    direction.push({a, c});
  }
  int time = 0, d = 0;
  snake.push_back({0,0});
  visited[0][0] = 1;
  while(1){
    time++;
    tie(y, x) = snake.back();
    tie(changeT, changeD) = direction.front();
    int ny = y + nxy[d][0]; 
    int nx = x + nxy[d][1];
    if(y < 0 || nx < 0 || ny >= n || nx >= n ) break;
    if(m[ny][nx] == 0){
      snake.push_back({ny,nx});
      if(snake.size() > 1 && visited[ny][nx]) break;
      else visited[ny][nx] = 1;
      visited[snake.front().first][snake.front().second] = 0;
      snake.pop_front();
    }
    else {
      snake.push_back({ny,nx});
      m[ny][nx] = 0;
    }
    if(time == changeT){
      if(changeD == 'D') d = (d + 1) % 4;
      else{
        if(d > 0) d = (d - 1) % 4  ;
        else d = ((-1 % 4) + 4) % 4;
      }
      direction.pop();
    }

  }
  cout << time << '\n';
  return 0;
}