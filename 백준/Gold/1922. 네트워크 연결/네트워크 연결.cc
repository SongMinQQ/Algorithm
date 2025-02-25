#include<bits/stdc++.h>
using namespace std;

int n, m, parent[1002], a, b, c, visited[1002];
long long result;
vector<tuple<int,int,int>> costs;

int find(int v){
  if(parent[v] == v) return v;
  return parent[v] = find(parent[v]);
}

bool unionFind(int a, int b){
  int aRoot = find(a);
  int bRoot = find(b);
  if(aRoot == bRoot) return false;
  parent[aRoot] = bRoot;
  return true;
}
void make(){
  for(int i = 1; i <= n; i++){
    parent[i] = i;
  }
}
int main(){
  cin >> n >> m;
  make();
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c;
    costs.push_back({c, a, b});
  }
  int cnt = 0;
  sort(costs.begin(),costs.end());
  for(tuple<int,int,int> i : costs){
    tie(c, a, b) = i;
    if(unionFind(a, b)){
      result += c;
      if(++cnt == n - 1) break;
    }
  }
  cout << result;
  return 0;
}