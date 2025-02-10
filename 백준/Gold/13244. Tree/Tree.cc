#include<bits/stdc++.h>
using namespace std;

bool visited[1002];
vector<int> v[1002];
int t, n, m, a, b;
string result;

void dfs(int s){
  visited[s] = 1;
  for(int i : v[s]){
    if(!visited[i]){
      dfs(i);
      // visited[i] = 1;
      // else {
      //   result = "graph";
      //   return;
      // }
    }
    
  }
  return;
}
void vectorClear(){
  for(int i = 0; i < 1002; i++){
    v[i].clear();
  }
}
int main(){
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> n >> m;
    for(int j = 0; j < m; j++){
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    // if((n - 1) != m){
    //   cout << "graph" << '\n';
    //   continue;
    // }
    int cnt = 0;
    for(int i = 1; i < n + 1; i++){
      if(!visited[i]){
        // if(v[i].size() == 0) continue;
        // else {
        dfs(i);
        cnt++;
        // }
      }
    }
    // cout << "\n------------" << cnt << '\n';
    if(cnt == 1 && ((n - 1) == m)) {
      result = "tree";
    }
    else{
      result = "graph";
    }
    cout << result << '\n';
    vectorClear();
    fill(&visited[0], &visited[1002], 0);
    result = " ";
  }
}