#include <bits/stdc++.h>
using namespace std;
set<string> s;
string line;

int main() {
  cin >> line;
  int n = line.size();

  // 길이 len짜리 부분 문자열을, 원래 문자열의 왼쪽부터 차례대로 뽑는다
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      s.insert(line.substr(i, len));
    }
  }

  cout << s.size() << '\n';
  return 0;
}
