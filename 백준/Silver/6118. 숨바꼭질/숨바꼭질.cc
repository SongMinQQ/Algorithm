#include <bits/stdc++.h>
using namespace std;

int n, m, hide = 25000, distance1 = 0, num1, num2, longDistance;
vector<int> v[20002];
int visited[20002];
vector<int> resultV;

void bfs(int s, int cnt){
  visited[s] = 1;
  
  // cout << "cnt : " << cnt << "node : " << s << '\n';
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    int cur = q.front();
    longDistance = max(longDistance,visited[cur]);
    q.pop();
    for(int i : v[cur]){
      if(!visited[i]){
        q.push(i);
        visited[i] = visited[cur] + 1;
      }
    }
  }
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> num1 >> num2;
    v[num1].push_back(num2);
    v[num2].push_back(num1);
  }
  bfs(1, 0);
  // cout << longDistance;
  for(int i = 1; i < n + 1; i++){
    if(visited[i] == (longDistance)){
      resultV.push_back(i);
      hide = min(hide,i);
    }
  }
  sort(resultV.begin(),resultV.end());
  cout << hide << ' ' << longDistance - 1 << ' ' << resultV.size();
}
