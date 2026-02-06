#include<bits/stdc++.h>
using namespace std;
int c, r, k, mp[1002][1002];
int main(){
  cin >> c >> r >> k;
  if(k > c * r){
        cout << 0;
        return 0;
    }
  int y = 1, x = 1;
  int num = 1;
  int dy[4] = {1, 0, -1, 0};
  int dx[4] = {0, 1, 0, -1};

  int dir = 0;

  while(num <= c * r){
      mp[y][x] = num;

      if(num == k){
          cout << x << " " << y;
          return 0;
      }
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if(ny < 1 || ny > r || nx < 1 || nx > c || mp[ny][nx] != 0){
          dir = (dir + 1) % 4;
          ny = y + dy[dir];
          nx = x + dx[dir];
      }
      y = ny;
      x = nx;
      num++;
  }
  return 0;
}