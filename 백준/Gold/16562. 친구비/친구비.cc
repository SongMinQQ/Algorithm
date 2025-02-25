#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> money;
int n, m, k, visited[10002], mon, parent[10002];
ll result;

int find(int v){
  if(parent[v] == v) return v;
  return parent[v] = find(parent[v]);
}

void unionFind(int a, int b){
  int aRoot = find(a);
  int bRoot = find(b);
  // if(aRoot == bRoot) return;
  money[aRoot] > money[bRoot] ? parent[aRoot] = bRoot : parent[bRoot] = aRoot;
}
int main(){
  cin >> n >> m >> k;
  money.push_back(0);
  for(int i = 1; i <= n; i++){
    cin >> mon;
    money.push_back(mon);
    parent[i] = i;
  }
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    unionFind(a, b);
  }
  for(int i = 1; i <= n; i++){
    // cout << find(i) << '\n';
    if(!visited[find(i)]){
      visited[find(i)] = 1;
      result += money[find(i)];
    }
  }
  if(result <= k) cout << result << '\n';
  else cout << "Oh no\n";
  return 0;
}