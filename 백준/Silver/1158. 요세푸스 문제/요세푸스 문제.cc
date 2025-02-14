#include<bits/stdc++.h>
using namespace std;
int n, k;
deque<int> dq;
vector<int> v;
int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    dq.push_back(i + 1);
  }
  while(!dq.empty()){
    for(int i = 0; i < k - 1; i++){
      int cur = dq.front();
      dq.pop_front();
      dq.push_back(cur);
    }
    int num = dq.front();
    dq.pop_front();
    v.push_back(num);
  }
  cout << '<';
  for(int i = 0; i < n; i++){
    if(i == n - 1) cout << v[i];
    else cout << v[i] << ", ";
  }
  cout << '>';
  return 0;
}