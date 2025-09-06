#include<bits/stdc++.h>
using namespace std;

int room[51][51], r, c, t, res;
vector<pair<int, int>> v, lists;
vector<int> num;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
void spread(){
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (room[i][j] > 4){
        lists.push_back({i, j});
        num.push_back(room[i][j]);
      }
    }
  }
  int idx = 0;
  for(pair<int,int> i: lists){
    int cnt = 0;
    int spreadNum = num[idx] / 5;
    for (int k = 0; k < 4; k++)
    {
      int ny = i.first + dy[k];
      int nx = i.second + dx[k];
      if (ny < 0 || nx < 0 || ny >= r || nx >= c || room[ny][nx] == -1)
        continue;
      cnt++;
      room[ny][nx] += spreadNum;
    }
    room[i.first][i.second] -= (spreadNum * cnt);
    if(room[i.first][i.second] <= 0)
      room[i.first][i.second] = 0;
    idx++;
  }

  lists.clear();
  num.clear();
}
void clean1(){
  int y, x, check = 0;
  tie(y, x) = v[0];
  for (int i = y - 1; i > 0; --i)
    room[i][0] = room[i - 1][0];
  for (int j = 0; j < c - 1; ++j)
    room[0][j] = room[0][j + 1];
  for (int i = 0; i < y; ++i)
    room[i][c - 1] = room[i + 1][c - 1];
  for (int j = c - 1; j > 1; --j)
    room[y][j] = room[y][j - 1];
  room[y][1] = 0;
}
void clean2()
{
  int y, x, check = 0;
  tie(y, x) = v[1];
  for (int i = y + 1; i < r - 1; ++i)
    room[i][0] = room[i + 1][0];
  for (int j = 0; j < c - 1; ++j)
    room[r - 1][j] = room[r - 1][j + 1];
  for (int i = r - 1; i > y; --i)
    room[i][c - 1] = room[i - 1][c - 1];
  for (int j = c - 1; j > 1; --j)
    room[y][j] = room[y][j - 1];
  room[y][1] = 0;
}
void cal(){
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if(room[i][j] != -1) res += room[i][j];
    }
  }
}
int main(){
  cin >> r >> c >> t;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> room[i][j];
      if(room[i][j] == -1) v.push_back({i, j});
    }
  }
  while(t--){
    //확산
    spread();
    //공청기 반시계 시계 1번씩
    clean1();
    clean2();
  }
  cal();
  cout << res;
  return 0;
}