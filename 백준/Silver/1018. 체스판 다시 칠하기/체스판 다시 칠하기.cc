#include <bits/stdc++.h>
using namespace std;

string line;
vector<string> v;
int n, m, ret = 999999999;

int cal(int col, int row) {
  int r1 = 0, r2 = 0;
  char ck = v[row][col];
  char ok = (ck == 'W' ? 'B' : 'W');
  for (int i = row; i < row + 8; i += 2)
    for (int j = col; j < col + 8; j += 2) {
      if (v[i][j] != ck) r1++;
      if (v[i][j] != ok) r2++;
    }
  for (int i = row + 1; i < row + 8; i += 2)
    for (int j = col + 1; j < col + 8; j += 2) {
      if (v[i][j] != ck) r1++;
      if (v[i][j] != ok) r2++;
    }
  for (int i = row; i < row + 8; i += 2)
    for (int j = col + 1; j < col + 8; j += 2) {
      if (v[i][j] == ck) r1++;
      if (v[i][j] == ok) r2++;
    }
  for (int i = row + 1; i < row + 8; i += 2)
    for (int j = col; j < col + 8; j += 2) {
      if (v[i][j] == ck) r1++;
      if (v[i][j] == ok) r2++;
    }
  return min(r1, r2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> line;
    v.push_back(line);
  }
  for (int row = 0; row <= n - 8; row++)
    for (int col = 0; col <= m - 8; col++)
      ret = min(ret, cal(col, row));
  cout << ret;
  return 0;
}
