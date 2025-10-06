#include<bits/stdc++.h>
using namespace std;

int n, num, cnt;
stack<int> v;

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> num;
    if(v.empty()){
      v.push(num); continue;
    }
    if(v.top() > num) v.push(num);
    else{
      while(!v.empty() && v.top() <= num){
        v.pop();
      }
      v.push(num);
    }
  }
  cout << v.size();
  return 0;
}