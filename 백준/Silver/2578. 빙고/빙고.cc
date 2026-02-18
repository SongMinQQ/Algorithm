#include<bits/stdc++.h>
using namespace std;

int bing[7][7], s[7][7], num;
map<int, pair<int, int>> m;
bool visited[7][7];

void print(){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      cout << visited[i][j];
    }
    cout << '\n';
  }
}
int check(){
  int ret = 0;
  for (int i = 0; i < 5; i++){
    int cnt = 0;
    for (int j = 0; j < 5; j++){
      if(visited[i][j])
        cnt++;
    }
    if(cnt == 5) ret++;
  }
  for (int i = 0; i < 5; i++){
    int cnt = 0;
    for (int j = 0; j < 5; j++){
      if(visited[j][i])
        cnt++;
    }
    if(cnt == 5) ret++;
  }
  int cnt = 0, cnt2 = 0;
  for (int i = 0; i < 5; i++){
    if(visited[i][i])
      cnt++;
  }
  for (int i = 4; i >= 0; i--){
    if(visited[4 - i][i])
      cnt2++;
  }
  if(cnt == 5)
    ret++;
  if(cnt2 == 5)
    ret++;
  return ret;
}
int main(){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      cin >> num;
      m[num] = {i,j};
    }
  }
  int ret = 0;
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      cin >> s[i][j];
      
    }
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      visited[m[s[i][j]].first][m[s[i][j]].second] = 1;
      ret++;
      if(check() >= 3){
        cout << ret;
        return 0;
      }
    }
  }
  
}