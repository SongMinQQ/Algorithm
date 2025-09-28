#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tc; 
    cin >> tc;
    vector<int> line;
    int ret = 0;
    for (int j = 0; j < 20; j++){
      int h;
      cin >> h;
      for (int k = 0; k < (int)line.size(); k++){
        if (line[k] > h)
          ret++;
      }
      line.push_back(h);
    }
    cout << tc << ' ' << ret << '\n';
  }
  return 0;
}
