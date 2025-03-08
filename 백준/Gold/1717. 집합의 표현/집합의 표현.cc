#include<bits/stdc++.h>
using namespace std;
int n, m, arr[1000002], a, b, w;

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
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  make(n);
  while(m--){
    cin >> w >> a >> b;
    if(w == 0) makeUnion(a, b);
    else{
      int checkA = find(a);
      int checkB = find(b);
      checkA == checkB ? cout << "YES\n" : cout << "NO\n";
    }
  }
  return 0;
}