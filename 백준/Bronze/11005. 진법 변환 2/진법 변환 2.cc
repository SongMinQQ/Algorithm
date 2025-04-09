#include<bits/stdc++.h>
using namespace std;
int n, b;
deque<int> dq;
int main(){
  cin >> n >> b;
  while(n > 0){
    int i;
    int num = n % b;
    n /= b;
    (num > 9) ?  i = num + 55 : i = num;
    dq.push_front(i);
  }
  for (int i = 0; i <dq.size(); i++){
    (dq[i] > 9) ? cout << (char)dq[i] : cout << dq[i];
  }
  return 0;
}