#include <bits/stdc++.h>
using namespace std;

int t, n;
char x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n;
    deque<char> dq;

    for (int i = 0; i < n; i++) {
      cin >> x;
      if (dq.empty()) dq.push_back(x);
      else {
        if (x <= dq.front()) dq.push_front(x);
        else dq.push_back(x);
      }
    }

    for (char c : dq) cout << c;
    cout << '\n';
  }
  return 0;
}