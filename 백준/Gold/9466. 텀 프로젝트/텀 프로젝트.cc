#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100002];
int state[100002];
int teamCnt;

void dfs(int x) {
  state[x] = 1;
  int nxt = a[x];

  if (state[nxt] == 0) {
    dfs(nxt);
  } else if (state[nxt] == 1) {
    int cur = nxt;
    do {
      teamCnt++;
      cur = a[cur];
    } while (cur != nxt);
  }
  state[x] = 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      state[i] = 0;
    }
    teamCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
        dfs(i);
      }
    }
    cout << n - teamCnt << '\n';
  }
  return 0;
}
