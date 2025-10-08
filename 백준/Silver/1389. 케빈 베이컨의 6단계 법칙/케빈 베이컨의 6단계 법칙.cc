#include<bits/stdc++.h>
using namespace std;

int n, m, n1, n2, visited[102], cur, diff = 99999999, ret;
vector<vector<int>> v;
int bfs(int s){
  int sum = 0;
  fill(&visited[0], &visited[n + 1], 0);
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    cur = q.front();
    q.pop();
    for(int i : v[cur]){
      if(i == s || visited[i])
        continue;
      else{
        q.push(i);
        visited[i] = visited[cur] + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++){
    sum += visited[i];
  }
  return sum;
}
int main(){
  cin >> n >> m;
  v.resize(n + 1);
  for (int i = 0; i < m; i++){
    cin >> n1 >> n2;
    v[n1].push_back(n2);
    v[n2].push_back(n1);
  }
  for (int i = 1; i <= n; i++){
    int diff2 = bfs(i);
    if(diff2 < diff){
      diff = diff2;
      ret = i;
    }
  }
  cout << ret;
  return 0;
}