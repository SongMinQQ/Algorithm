#include<bits/stdc++.h>
using namespace std;
bool visited[2002];
int n, m, a, b, result;
vector<int> v[2002];

void dfs(int node, int depth){
  if(depth == 4){
    result = 1;
    return;
  }
  visited[node] = 1;
  for(int i : v[node]){
    if(!visited[i]) dfs(i, depth + 1);
  }
  visited[node] = 0;
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i = 0; i < n; i++){
    dfs(i, 0);
    if(result) break;
  }
  cout << result << '\n';
  return 0;
  
}