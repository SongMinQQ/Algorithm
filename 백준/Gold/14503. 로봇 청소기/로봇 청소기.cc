#include<bits/stdc++.h>
using namespace std;
int room[53][53], n, m, r, c, d, ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
  cin >> n >> m >> r >> c >> d;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> room[i][j];
    }
  }
  while(1){
    //현재칸 청소 안되있으면 청소
    if(room[r][c] == 0){
      room[r][c] = 2;
      ret++;
    }
    int cnt = 0;
    for (int i = 0; i < 4; i++){
      int ny = r + dy[i];
      int nx = c + dx[i];
      // 경계를 벗어나거나 청소되지 않은 빈 칸 체크
      if(ny < 0 || nx < 0 || ny >= n || nx >= m){
        cnt++;
        continue;
      }
      if (room[ny][nx] == 1 || room[ny][nx] == 2)
        cnt++;
    }
    //청소되지 않은 빈 칸이 없는 경우
    //바라보는 방향을 유지한 채로 한 칸 후진
    if(cnt == 4){
      r += -dy[d];
      c += -dx[d];
      // 벽체크
      if(r < 0 || c < 0 || r >= n || c >= m)
        break;
      if (room[r][c] == 1)
        break;
    }
    //청소되지 않은 빈 칸이 있는 경우
    else{
      // 반시계 방향 회전
      for (int i = 0; i < 4; i++){
        d = (d + 3) % 4;
        int ny = r + dy[d];
        int nx = c + dx[d];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        // 바라보는 방향 기준 앞칸 청소되어있지 않으면 그대로 진행
        if (room[ny][nx] == 0){
          r = ny;
          c = nx;
          break;
        }
        // 아니면 전진 안함, 다시 회전
      }
    }
  }
  cout << ret;
  return 0;
}