#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
vector<pair<int,int>> v[1002];
int bfs(int s, int d){
  int visited[1002];
  fill(&visited[0], &visited[1001], 0);
  queue<pair<int,int>> q;
  q.push({s, 0});
  while(!q.empty()){
    int cur = q.front().first, dist = q.front().second;
    q.pop();
    for(pair<int,int> i : v[cur]){
      if(!visited[i.first]){
        visited[i.first] = dist + i.second;
        q.push({i.first, visited[i.first]});
      }
    }
  }
  return visited[d];
}
int main(){
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++){
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    cout << bfs(a, b) << '\n';
  }
  return 0;
}