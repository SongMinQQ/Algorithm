#include<bits/stdc++.h>
using namespace std;

int n, num1, num2, arr[300002];
vector<pair<int,int>> v;

void make(){
  for(int i =1; i <= n; i++){
    arr[i] = i;
  }
}
int find(int a){
  if(arr[a] == a) return a;
  return arr[a] = find(arr[a]);
}
bool unionFind(int a, int b){
  int aRoot = find(a);
  int bRoot = find(b);
  if(aRoot == bRoot) return false;
  arr[aRoot] = bRoot;
  return true;
}
int main(){
  cin >> n;
  for(int i = 0; i < n - 2; i++){
    cin >> num1 >> num2;
    v.push_back({num1, num2});
  }
  make();
  for(pair<int, int> i : v){
    unionFind(i.first, i.second);
  }
  int resultNum1 = find(1), resultNum2;
  for(int i = 1; i <= n; i++){
    if(find(i) != resultNum1) {resultNum2 = find(i); break;}
  }
  cout << resultNum1 << ' ' << resultNum2 << '\n';
  return 0;

}