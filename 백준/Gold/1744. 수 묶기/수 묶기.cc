#include <bits/stdc++.h>
using namespace std;

vector<int> po;
vector<int> ne;
int ones, zeros;
long long result = 0;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
      int x;
      cin >> x;
      if (x > 1) po.push_back(x);
      else if (x == 1) ones++;
      else if (x == 0) zeros++;
      else ne.push_back(x);
  }
  sort(po.begin(), po.end(), greater<int>());
  sort(ne.begin(), ne.end());

  for (int i = 0; i + 1 < (int)po.size(); i += 2) {
      result += 1LL * po[i] * po[i+1];
  }
  if (po.size() % 2 == 1) {
      result += po.back();
  }

  for (int i = 0; i + 1 < (int)ne.size(); i += 2) {
      result += 1LL * ne[i] * ne[i+1];
  }
  if (ne.size() % 2 == 1) {
      if (zeros == 0) {
          result += ne.back();
      }
  }

  result += ones;

  cout << result << "\n";
  return 0;
}
