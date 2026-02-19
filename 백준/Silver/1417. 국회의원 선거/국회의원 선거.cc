#include<bits/stdc++.h>
using namespace std;

int n, a, b, ret;
priority_queue < int, vector<int>, less<int>> pq;
int main(){
  cin >> n >> a;
  for (int i = 1; i < n; i++){
    cin >> b;
    pq.push(b);
  }
  if(n == 1){
    cout << 0;
    return 0;
  }
  while(!pq.empty()){
    if(pq.top() >= a){
      a++;
      ret++;
      int cur = pq.top();
      pq.pop();
      pq.push(cur - 1);
    }
    else{
      pq.pop();
    }
  }
  cout << ret;
  return 0;
}