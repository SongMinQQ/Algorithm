#include<bits/stdc++.h>
using namespace std;

int R, C, M, r, c, s, d, z, a[103][103], ret;
map<int, vector<int>> sharks;
pair<int,int> move(int pos, int dir, int len, int speed){
  if(len == 1) return {pos, dir};
  int period = 2 * (len - 1);
  int t = speed % period;
  int x = (pos + dir * t) % period;
  if(x < 0) x += period;
  if(x < len){
    return {x, dir};
  }else{
    return {2 * (len - 1) - x, -dir};
  }
}
void moveShark(){
  static int tmp[103][103];
  memset(tmp, 0, sizeof(tmp));
  map<int, vector<int>> nextSharks;
  for(auto i : sharks){
    int sharkNum = i.first;
    vector<int> sharkInfo = i.second;
    int r = sharkInfo[0], c = sharkInfo[1], speed = sharkInfo[2], direction = sharkInfo[3], z = sharkInfo[4];
    int nr= r, nc = c, nd = direction;
    if(direction == 1 || direction == 2){
      int dir = direction == 2 ? 1 : -1;
      auto t = move(r, dir, R, speed);
      nr = t.first;
      nd = t.second == 1 ? 2 : 1;
    }
    else{
      int dir = direction == 3 ? 1 : -1;
      auto t = move(c, dir, C, speed);
      nc = t.first;
      nd = t.second == 1 ? 3 : 4;
    }
    if (tmp[nr][nc] == 0){
      tmp[nr][nc] = sharkNum;
      nextSharks[sharkNum] = {nr, nc, speed, nd, z};
    } else {
      int other = tmp[nr][nc];
      int zOther = nextSharks[other][4];
      if (z > zOther){
        nextSharks.erase(other);
        tmp[nr][nc] = sharkNum;
        nextSharks[sharkNum] = {nr, nc, speed, nd, z};
      }
    }
  }
  memset(a, 0, sizeof(a));
  for(auto &kv : nextSharks){
    int id = kv.first;
    int rr = kv.second[0], cc = kv.second[1];
    a[rr][cc] = id;
  }
  sharks.swap(nextSharks);
}
int main(){
  cin >> R >> C >> M;
  for (int i = 1; i <= M; i++){
    cin >> r >> c >> s >> d >> z;
    r--;
    c--;
    a[r][c] = i;
    sharks[i] = {r, c, s, d, z};
  }
  for (int i = 0; i < C; i++){
    for (int j = 0; j < R; j++){
      if(a[j][i] != 0){
        //cout << i << ' ' << sharks[a[j][i]][4] << '\n';
        ret += sharks[a[j][i]][4];
        sharks.erase(a[j][i]);
        a[j][i] = 0;
        break;
      }
    }
    moveShark();
  }
  cout << ret;
  return 0;
}