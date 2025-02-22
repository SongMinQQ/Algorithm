#include <bits/stdc++.h>
using namespace std;

int n, ans, h[100002];
stack<int> s;

int main(){
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> h[i];
  s.push(0);
  for (int i = 1; i <= n + 1; i++){
    while (!s.empty() && h[s.top()] > h[i])
    {
      int check = s.top();
      s.pop();
      ans = max(ans, h[check] * (i - s.top() - 1));
    }
    s.push(i);
  }
  cout << ans;
  return 0;
}