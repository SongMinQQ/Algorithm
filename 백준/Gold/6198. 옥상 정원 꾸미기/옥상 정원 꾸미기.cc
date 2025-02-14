#include<bits/stdc++.h>
using namespace std;

int n, num;
long long cnt;
stack<int> s;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    while(s.size()&&s.top() <= num){
      s.pop();
    }
    if(s.size()){
      cnt+=s.size();
    }
    s.push(num);
  }
  cout << cnt;
  return 0;
}