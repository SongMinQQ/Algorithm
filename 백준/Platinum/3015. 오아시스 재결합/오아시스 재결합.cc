#include <bits/stdc++.h>
using namespace std;

stack<pair<long long, long long>> s;
// stack<long long> s2;
long long num, n, result;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    int cnt = 1;
    //입력된 숫자가 이전값보다 큰 경우(오름차순)
    while(s.size() && s.top().first <= num){
      result += s.top().second;
      //같은 숫자의 경우
      if(s.top().first == num){
        cnt=s.top().second + 1;
      }
      else cnt = 1;
      s.pop();
    }
    //작은 수일경우(내림차순)
    if(s.size()) result++;
    s.push({num, cnt});
  }
  cout << result;
  return 0;
}