#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n, a, b;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a >> b;
    v.push_back({a, b});
  }

  for (int i = 0; i < n; ++i)
  {
    int rank = 1;
    for (int j = 0; j < n; ++j)
    {
      if (i == j)
        continue;
      if (v[j].first > v[i].first && v[j].second > v[i].second)
      {
        rank++;
      }
    }
    cout << rank << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}