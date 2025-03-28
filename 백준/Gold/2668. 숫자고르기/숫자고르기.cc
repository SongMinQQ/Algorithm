#include<bits/stdc++.h>
using namespace std;

int n, num;
vector<int> v[102], result;
bool visited[100];
bool dfs(int node, int root){
  visited[node] = 1;
  for(int i : v[node]){
    if(i == root) return true;
    if(!visited[i] && dfs(i, root))
      return true;
  }
  return false;
}

void answerPush(){
  for(int i = 1; i <= n; i++){
    if(visited[i]) result.push_back(i);
  }
}
int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> num;
    v[i].push_back(num);
  }
  for(int i = 1; i <= n; i++){
    if(dfs(i, i)) result.push_back(i);
    fill(&visited[0], &visited[102], 0);
  }
  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for(int i : result){
    cout << i << '\n';
  }
  return 0;
}