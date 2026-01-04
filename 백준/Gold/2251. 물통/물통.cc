#include<bits/stdc++.h>
using namespace std;

int a, b, c;
bool visited[202][202][202];
set<int> ret;
void dfs(int q, int w, int e){
  if(visited[q][w][e]) return;
  visited[q][w][e] = 1;
  if(q == 0){
    ret.insert(e);
  }
  //A => B
  if(q + w > b){
    dfs(q + w - b, b, e);
  }
  else{
    dfs(0, q + w, e);
  }
  //A => C
  if(q + e > c){
    dfs(q + e - c, w, c);
  }
  else{
    dfs(0, w, q + e);
  }
  //B => A
  if(w + q > a){
    dfs(a, w + q - a, e);
  }
  else{
    dfs(w + q, 0, e);
  }
  //B => C
  if(w + e > c){
    dfs(q, w + e - c, c);
  }
  else{
    dfs(q, 0, w + e);
  }
  //C => A
  if(e + q > a){
    dfs(a, w, e + q - a);
  }
  else{
    dfs(e + q, w, 0);
  }
  //C => B
  if(e + w > b){
    dfs(q, b, e + w - b);
  }
  else{
    dfs(q, e + w, 0);
  }
}
int main(){
  cin >> a >> b >> c;
  dfs(0, 0, c);
  for(auto i : ret){
    cout << i << ' ';
  }
  return 0;
}