#include<bits/stdc++.h>
using namespace std;

int n, m, l, k, n1, n2, ret=INT_MAX;
vector<pair<int, int>> pq, q;
int main(){
  cin >> n >> m >> l >> k;
  for (int i = 0; i < k; i++){
    cin >> n1 >> n2;
    pq.push_back({n1, n2});
    q.push_back({n2,n1});
  }
  int best = 0;

  for (int i = 0; i < k; i++) {
    int xx = min(pq[i].first, max(0, n - l));
    for (int j = 0; j < k; j++) {
      int yy = min(pq[j].second, max(0, m - l));

      int cnt = 0;
      for (int t = 0; t < k; t++) {
        int x = pq[t].first, y = pq[t].second;
        if (xx <= x && x <= xx + l && yy <= y && y <= yy + l) cnt++;
      }
      best = max(best, cnt);
    }
  }

  cout << (k - best) << "\n";
  return 0;
}