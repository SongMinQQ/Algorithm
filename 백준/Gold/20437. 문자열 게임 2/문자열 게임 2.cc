#include<bits/stdc++.h>
using namespace std;


string w;
int t, k;
const int MAX_NUMBER = 9999999;
int main(){
  cin >> t;
  while(t--){
    cin >> w >> k;
    vector<int> pos[26];
    for (int i = 0; i < (int)w.size(); i++)
    {
      pos[w[i] - 'a'].push_back(i);
    }

    int ret1 = MAX_NUMBER, ret2 = 0;
    for (int c = 0; c < 26; c++)
    {
      if ((int)pos[c].size() < k)
        continue;
      for (int i = 0; i + k - 1 < pos[c].size(); i++)
      {
        int l = pos[c][i];
        int r = pos[c][i + k - 1];
        int len = r - l + 1;
        ret1 = min(ret1, len);
        ret2 = max(ret2, len);
      }
    }

    if (ret2 == 0)
      cout << -1 << '\n';
    else
      cout << ret1 << ' ' << ret2 << '\n';
  }
  return 0;
}