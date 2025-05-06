#include<bits/stdc++.h>
using namespace std;

int x, m, w, cnt;
string line;

int main() {
  cin >> x >> line;
  deque<char> q;
  for(char c : line) q.push_back(c);

  while(!q.empty()) {
    if(q.front() == 'M') {
      if(abs((m + 1) - w) <= x) {
        m++;
        q.pop_front();
        cnt++;
      } else if(q.size() >= 2 && q[1] == 'W' && abs(m - (w + 1)) <= x) {
        w++;
        q.erase(q.begin() + 1);
        cnt++;
      } else break;
    } else {
      if(abs((w + 1) - m) <= x) {
        w++;
        q.pop_front();
        cnt++;
      } else if(q.size() >= 2 && q[1] == 'M' && abs((m + 1) - w) <= x) {
        m++;
        q.erase(q.begin() + 1);
        cnt++;
      } else break;
    }
  }

  cout << cnt;
}
