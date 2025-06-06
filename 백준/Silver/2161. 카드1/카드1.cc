#include<bits/stdc++.h>
using namespace std;

int n;
deque<int> dq;
int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    dq.push_back(i);
  }
  while(dq.size() != 1){
    cout << dq.front() << ' ';
    dq.pop_front();
    dq.push_back(dq.front());
    dq.pop_front();
  }
  cout << dq.front();
  return 0;
}