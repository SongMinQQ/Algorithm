#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt = 1;
bool dfs(int s, int parent, vector<vector<int>> & v, vector<bool> & visited){
  visited[s] = 1;
  if(v[s].empty())
    return true;
  for (int i : v[s]) {
    if (!visited[i]) {
      if (!dfs(i, s, v, visited)) return false;
    } else {
      if (i != parent) return false; 
    }
  }
  return true;
}
int main(){
  while(1){
    cin >> a >> b;
    if(a == 0 && b == 0) break;
    int c, d, t = 0;
    vector<vector<int>> v;
    vector<bool> visited(a + 2);
    fill(visited.begin(), visited.end(), 0);
    v.resize(a + 2);
    for (int i = 0; i < b; i++){
      cin >> c >> d;
      v[c].push_back(d);
      v[d].push_back(c);
    }
    for (int i = 1; i <= a; i++){
      if(!visited[i]){
        if(dfs(i, i, v, visited)){
          t++;
        }
      }
    }
    cout << "Case " << cnt << ": ";
    if(t > 1){
      cout << "A forest of " << t << " trees.\n";
    }
    else if(t == 1){
      cout << "There is one tree.\n";
    }
    else{
      cout << "No trees.\n";
    }
    cnt++;
  }
}