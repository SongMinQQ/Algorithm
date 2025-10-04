#include<bits/stdc++.h>
using namespace std;

int n, visited[100003], p, c, k, isApple[100003], cnt;
vector<vector<int>> v;
void dfs(int c){
  for(int i : v[c]){
    if(!visited[i]){
      visited[i] = visited[c] + 1;
      dfs(i);
    }
  }
}
int main(){
  cin >> n >> k;
  v.resize(n);
  for (int i = 1; i < n; i++){
    cin >> p >> c;
    v[p].push_back(c);
  }
  for (int i = 0; i < n; i++){
    cin >> isApple[i];
  }
  visited[0] = 1;
  dfs(0);
  for (int i = 0; i < n; i++){
    if(isApple[i] == 1 && (visited[i] - 1) <= k)
      cnt++;
  }
  cout << cnt;
  return 0;
}
