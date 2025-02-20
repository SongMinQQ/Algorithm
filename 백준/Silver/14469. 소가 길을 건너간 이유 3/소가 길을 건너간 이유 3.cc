#include<bits/stdc++.h>
using namespace std;

int n, a, t, result;
vector<pair<int,int>> cow;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> t;
    cow.push_back({a, t});
  }
  sort(cow.begin(),cow.end());
  for(int i = 0; i < cow.size(); i++){
    if(result < cow[i].first) result = (cow[i].first + cow[i].second);
    else result += (cow[i].second);
  }

  cout << result << '\n';
  return 0;
}