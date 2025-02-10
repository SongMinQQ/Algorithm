#include <bits/stdc++.h>
using namespace std;

int n, m, visited[100002], num1, num2, x, cnt;
vector<int> v[100002];

void bfs(int s){
  visited[s] = 1;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int cur = q.front();
    
    q.pop();
    for(int i : v[cur]){
      if(!visited[i]){
        q.push(i);
        cnt++;
        visited[i] = visited[cur] + 1;
      }
    }
  }
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> num1 >> num2;
    v[num2].push_back(num1);
  }
  cin >> x;
  // for(int i = 1; i <= n; i++){
  //   if(!visited[i]){
  bfs(x);
  //   }
  // }
  // cout << "\n\n" << cnt << "\n\n";
  cout << cnt;
  return 0;
}