#include<bits/stdc++.h>
using namespace std;

int n, a, b, visited[52], cnt = 99999999;
vector<vector<int>> v;
int main(){
  cin >> n;
  v.resize(n + 1);
  while(1){
    cin >> a >> b;
    if(a == -1 && b == -1) break;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<pair<int, int>> ret;
  for (int i = 1; i <= n; i++){
    fill(&visited[0], &visited[n + 1], 0);
    visited[i] = 1;
    int friendCnt = 0;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for(int j : v[cur]){
        if(!visited[j]){
          q.push(j);
          visited[j] = visited[cur] + 1;
        }
      }
    }
    for (int j = 1; j <= n; j++){
      friendCnt = max(friendCnt, visited[j] - 1);
    }
    cnt = min(cnt, friendCnt);
    ret.push_back({i, friendCnt});
  }
  vector<int> result;
  for(auto i : ret){
    int hubo = i.first, friendNum = i.second;
    if(friendNum == cnt){
      result.push_back(hubo);
    }
  }
  cout << cnt << ' ' << result.size() << '\n';
  for(int i : result){
    cout << i << ' ';
  }
  return 0;
}