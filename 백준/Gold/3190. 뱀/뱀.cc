#include<bits/stdc++.h>
using namespace std;

deque<pair<int,int>> snake;
int n, k, l, m[102][102], a, b, y, x, changeT, changeD;
bool visited[102][102] = {0};
char c;
queue<pair<int, char>> direction; 
const int nxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void print(int time){
  cout << time << '\n';
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << visited[i][j];
    }
    cout << '\n';
  }
  cout <<'\n';
}
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
  /*
  방향 초기값 
  오른쪽(y 그대로 x만 + 1) {0, 1}
  아래쪽(x 그대로 y만 + 1) {1, 0}
  왼쪽(y 그대로 x만 - 1) {0, -1}
  위쪽(x 그대로 y만 - 1) {-1, 0}
  사과 만나면 몸길이 늘어나는 로직은 대체 어케함?
  생각해보니까 그냥 사과 만나면 pop을 안하면 될듯 오로지 push만
  */
  int time = 0, d = 0;
  snake.push_back({0,0});
  visited[0][0] = 1;
  while(1){
    // print(time);
    time++;
    tie(y, x) = snake.back();
    tie(changeT, changeD) = direction.front();
    
    int ny = y + nxy[d][0]; 
    int nx = x + nxy[d][1]; 
    // cout << "current time : " << time << " y : " << ny << " x : " << nx << '\n';

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
      // if(visited[ny][nx]) break;
      // else visited[ny][nx] = 1;
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
    // cout << "current time : " << time << " size : " << snake.size() << '\n';

  }
  cout << time << '\n';
  return 0;
}