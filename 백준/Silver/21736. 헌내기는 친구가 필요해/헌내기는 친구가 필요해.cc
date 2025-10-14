#include<bits/stdc++.h>
using namespace std;

int n, m, y, x, cnt;
char campus[602][602];
bool visited[602][602];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int main(){
  cin >> n >> m;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    for (int j = 0; j < line.size(); j++){
      campus[i][j] = line[j];
      if(line[j] == 'I') {
        visited[i][j] = 1;
        q.push({i, j});
      }
    }
  }
  while(!q.empty()){
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || campus[ny][nx] == 'X') continue;
      q.push({ny, nx});
      visited[ny][nx] = 1;
      if(campus[ny][nx] == 'P')cnt++;
    }
  }
  cnt > 0 ? cout << cnt : cout << "TT";
  return 0;
}