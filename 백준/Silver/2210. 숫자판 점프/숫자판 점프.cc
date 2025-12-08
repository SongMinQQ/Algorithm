#include<bits/stdc++.h>
using namespace std;

char a[6][6];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
set<string> s;
void dfs(int y, int x, vector<char> v){
  if(v.size() == 6){
    string b = "";
    for(char i : v){
      b += i;
    }
    s.insert(b);
    return;
  }
  for (int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
      continue;
    v.push_back(a[ny][nx]);
    dfs(ny, nx, v);
    v.pop_back();
  }
}
int main(){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      vector<char> v;
      dfs(i, j, v);
    }
  }
  cout << s.size();
  return 0;
}