#include<bits/stdc++.h>
using namespace std;
int n, m, num, arr[203], result;
vector<int> v;
void make(int a){
  for(int i = 1; i <= a; i++){
    arr[i] = i;
  }
}
int find(int a){
  if(arr[a] == a) return a;
  return arr[a] = find(arr[a]);
}
bool makeUnion(int a, int b){
  int aRoot = find(a);
  int bRoot = find(b);
  if(aRoot == bRoot) return false;
  arr[aRoot] = bRoot;
  return true;
}

int main(){
  cin >> n >> m;
  make(n);
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cin >> num;
      if(num == 1) makeUnion(i, j);
    }
  }
  cin >> num;
  int root = arr[num];
  for (int i = 1; i < m; i++){
    cin >> num;
    if(find(num) != find(root))
      result = 1;
  }
  result ? cout << "NO" : cout << "YES";
  return 0;
}