#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int a[1004][1004], visited[1004][1004], m, n, findMax = 0, y, x;
queue<pair<int, int>> q;

void bfs() {
  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == -1 || visited[ny][nx]) continue;
      visited[ny][nx] = visited[y][x] + 1;
      findMax = max(findMax, visited[ny][nx]);
      q.push({ny, nx});
    }
  }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0 && visited[i][j] == 0) {
          findMax = -1;
          break;
        }
      }
    }
    if(findMax > 0){
        cout << findMax - 1;
    }
    else cout << findMax;
    return 0;
}
