#include<bits/stdc++.h>
using namespace std;

int n, m, ret;
char a[52][52];
bool visited[52][52];
void bfs1(int y, int x){
  visited[y][x] = 1;
  queue<pair<int, int>> q;
  int cy, cx;
  q.push({y, x});
  while(!q.empty()){
    tie(cy, cx) = q.front();
    q.pop();
    cx++;
    if(a[cy][cx] == '-'){
      q.push({cy, cx});
      visited[cy][cx] = 1;
    }
  }
}
void bfs2(int y, int x){
  visited[y][x] = 1;
  queue<pair<int, int>> q;
  int cy, cx;
  q.push({y, x});
  while(!q.empty()){
    tie(cy, cx) = q.front();
    q.pop();
    cy++;
    if(a[cy][cx] == '|'){
      q.push({cy, cx});
      visited[cy][cx] = 1;
    }
  }
}
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    for (int j = 0; j < line.size(); j++){
      a[i][j] = line[j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(a[i][j] == '-' && !visited[i][j]){
        bfs1(i, j);
        ret++;
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(a[i][j] == '|' && !visited[i][j]){
        bfs2(i, j);
        ret++;
      }
    }
  }
  cout << ret;
  return 0;
}