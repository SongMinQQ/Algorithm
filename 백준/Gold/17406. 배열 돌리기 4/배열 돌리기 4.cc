#include<bits/stdc++.h>
using namespace std;

int a[105][105], b[105][105], visited[105][105], n, m, k, r, c, s, dir, result = 999999999, sy, sx, ey, ex;
vector<tuple<int, int, int>> v;
vector<int> idx;
vector<pair<int, int>> v2;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
void cal(){
  for (int i = 0; i < n; i++){
    int plus = 0;
    for (int j = 0; j < m; j++){
      plus += a[i][j];
    }
    result = min(result, plus);
  }
}

void go(int y, int x, int first){
  if(!first && y == sy && x == sx) dir = (dir + 1) % 4;
  if(!first && y == sy && x == ex) dir = (dir + 1) % 4;
  if(!first && y == ey && x == ex) dir = (dir + 1) % 4;
  if(!first && y == ey && x == sx) dir = (dir + 1) % 4;
  int ny = y + dy[dir];
  int nx = x + dx[dir];
  if (ny < sy || nx < sx || ny > ey || nx > ex){
    dir = (dir + 1) % 4;
    ny = y + dy[dir];
    nx = x + dx[dir];
  }
  if(visited[ny][nx]) return;
  visited[ny][nx] = 1;
  v2.push_back({ny, nx});
  go(ny, nx, 0);
}
void rotateAll(int y, int x, int cnt){
  for (int i = 1; i <= cnt; i++){
    sy = y - 1 * i;
    sx = x - 1 * i;
    ey = y + 1 * i;
    ex = x + 1 * i;
    v2.clear();
    dir = 0;
    memset(visited, 0, sizeof(visited));
    visited[sy][sx] = 1;
    v2.push_back({sy, sx});
    go(sy, sx, 1);
    vector<int> v3;
    v3.reserve(v2.size());
    for (auto &c : v2) v3.push_back(b[c.first][c.second]);
    if (!v3.empty()) rotate(v3.begin(), v3.end() - 1, v3.end());

    for (int k = 0; k < (int)v2.size(); k++)
      b[v2[k].first][v2[k].second] = v3[k];
  }
}
int solve(){
  for (int i : idx){
    int y2, x2, cnt2;
    tie(y2, x2, cnt2) = v[i];
    rotateAll(y2, x2, cnt2);
  }
  int mn = 999999999;
  for (int i = 0; i < n; i++){
    int cnt = 0;
    for (int j = 0; j < m; j++)
      cnt += b[i][j];
    mn = min(mn, cnt);
  }
  return mn;
}
int main(){
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < k; i++){
    cin >> r >> c >> s;
    r--;
    c--;
    v.push_back({r, c, s});
    idx.push_back(i);
  }
  do{
    memcpy(b, a, sizeof(b));
    result = min(result, solve());
  }while(next_permutation(idx.begin(), idx.end()));
  cout << result;
  return 0;
}