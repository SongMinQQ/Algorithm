#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
  while (1){
    ll ans = 0, h[100003];
    stack<ll> s;
    cin >> n;
    if (n == 0) break;
    for (int i = 1; i <= n; i++)
      cin >> h[i];
    h[0] = 0;
    h[n + 1] = 0;
    s.push(0);
    for (int i = 1; i <= n + 1; i++){
      while (!s.empty() && h[s.top()] > h[i])
      {
        ll check = s.top();
        s.pop();
        ans = max(ans, h[check] * (i - s.top() - 1));
      }
      s.push(i);
    }
    cout << ans << '\n';
  }
  return 0;
}