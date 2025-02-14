#include<bits/stdc++.h>
using namespace std;

int n, num, result[500002];
stack<pair<int, int>> s;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    while(s.size() && s.top().first <= num){
      s.pop();
    }
    if(s.size()&&s.top().first > num){
      result[i + 1] = s.top().second;
    }
    s.push({num, i + 1});
  }
  for(int i = 1; i < n + 1; i++){
    cout << result[i] << ' ';
  }
  return 0;
}