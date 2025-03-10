#include<bits/stdc++.h>
using namespace std;
int n, r, q, u ,v, nodeNum[100003],visited[100003], num;
vector<int> tree[100003];
void makeTree(int curNode){
  visited[curNode] = 1;
  nodeNum[curNode] = 1;
  for(int i : tree[curNode]){
    if(!visited[i]){
      makeTree(i);
      nodeNum[curNode] += nodeNum[i];
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> r >> q;
  for(int i = 1; i < n; i++){
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  makeTree(r);
  for(int i = 0; i < q; i++){
    cin >> num;
    cout << nodeNum[num] << '\n';
  }
  return 0;

}