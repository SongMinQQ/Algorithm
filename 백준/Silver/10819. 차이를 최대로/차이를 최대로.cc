#include<bits/stdc++.h>
using namespace std;

int n, num, ret;
vector<int> a;
bool visited[10];
void go(vector<int> v){
  if(v.size() == n){
    int p = 0;
    for (int i = 1; i < n; i++){
      p += abs(v[i - 1] - v[i]);
    }
    ret = max(ret, p);
    return;
  }
  for (int i = 0; i < n; i++){
    if(!visited[i]){
      visited[i] = 1;
      v.push_back(a[i]);
      go(v);
      visited[i] = 0;
      v.pop_back();
    }
  }
}
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> num;
    a.push_back(num);
  }
  vector<int> v;
  go(v);
  cout << ret;
  return 0;
}