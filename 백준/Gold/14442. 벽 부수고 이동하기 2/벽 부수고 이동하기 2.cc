#include <bits/stdc++.h>
using namespace std;

int n, m, k, y, x, w;
int a[1002][1002];
int dist[1002][1002][11];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string line; 
    cin >> line;
    for (int j = 0; j < m; j++) {
      a[i][j] = line[j] - '0';
    }
  }

  queue<tuple<int,int,int>> q;
  dist[0][0][0] = 1;
  q.push({0, 0, 0});
  int ans = -1;
  while (!q.empty()) {
    tie(y, x, w) = q.front();
    q.pop();

    if (y == n - 1 && x == m - 1) {
      ans = dist[y][x][w];
      break; 
    }

    for (int dir = 0; dir < 4; dir++) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

      if (a[ny][nx] == 0) {
        if (dist[ny][nx][w] == 0) {
          dist[ny][nx][w] = dist[y][x][w] + 1;
          q.push({ny, nx, w});
        }
      }
      else {
        if (w < k && dist[ny][nx][w + 1] == 0) {
          dist[ny][nx][w + 1] = dist[y][x][w] + 1;
          q.push({ny, nx, w + 1});
        }
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
