#include<bits/stdc++.h>
using namespace std;

int n, x, y, m, n1, n2, visited[103];
vector<int> v[103];
void dfs(int c){
  for(int i : v[c]){
    if(!visited[i]){
      visited[i] = visited[c] + 1;
      dfs(i);
    }
  }
}
int main(){
  cin >> n >> x >> y >> m;
  for (int i = 0; i < m; i++){
    cin >> n1 >> n2;
    v[n1].push_back(n2);
    v[n2].push_back(n1);
  }
  visited[x] = 1;
  dfs(x);
  visited[y] != 0 ? cout << visited[y] - 1: cout << -1;
  return 0;
}