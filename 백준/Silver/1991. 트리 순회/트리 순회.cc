#include<bits/stdc++.h>
using namespace std;
vector<int> tree[26];
vector<char> checkV;
char sNode, node1, node2;
bool visited[28];
int n;
void preOrder(int nod){
  visited[nod] = 1;
  char node = nod + 'A';
  cout << node;
  if(tree[nod].size()){
    if(tree[nod][0] >= 0) preOrder(tree[nod][0]);
    if(tree[nod][1] >= 0) preOrder(tree[nod][1]);
  }
}
void postOrder(int nod){
  char node = nod + 'A';
  if(visited[nod] == 0){
  if(tree[nod].size()){
    if(tree[nod][0] >= 0) postOrder(tree[nod][0]);
    if(tree[nod][1] >= 0) postOrder(tree[nod][1]);
    }
    visited[nod] = 1;
    cout << node;
  }
}
void inOrder(int nod){
  if(nod < 0) return;

  int left = tree[nod][0];
  int right = tree[nod][1];

  if(left >= 0)
    inOrder(left);

  cout << char(nod + 'A');

  if(right >= 0)
    inOrder(right);
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> sNode >> node1 >> node2;
    checkV.push_back(sNode);
    tree[sNode - 'A'].push_back(node1 - 'A');
    tree[sNode - 'A'].push_back(node2 - 'A');
  }
  preOrder(0);
  fill(&visited[0], &visited[28], 0);
  cout << '\n';
  inOrder(0);
  fill(&visited[0], &visited[28], 0);
  cout << '\n';
  postOrder(0);
  return 0;
}