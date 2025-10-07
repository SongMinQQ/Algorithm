#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  bool first = true;
  while (cin >> k)
  {
    if (k == 0)
      break;

    vector<int> s(k);
    for (int i = 0; i < k; i++)
      cin >> s[i];

    if (!first)
      cout << '\n';
    first = false;

    vector<int> cur;
    cur.reserve(6);

    function<void(int, int)> dfs = [&](int idx, int chosen){
      if (chosen == 6){
        for (int i = 0; i < 6; i++)
        {
          if (i)
            cout << ' ';
          cout << cur[i];
        }
        cout << '\n';
        return;
      }
      if (idx == k)
        return;

      for (int i = idx; i < k; i++){
        cur.push_back(s[i]);
        dfs(i + 1, chosen + 1);
        cur.pop_back();
      }
    };

    dfs(0, 0);
  }
  return 0;
}
