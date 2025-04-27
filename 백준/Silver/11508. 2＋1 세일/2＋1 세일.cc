#include<bits/stdc++.h>
using namespace std;

int n, result, cnt, num;
vector<int> v;
int main(){
  cin >> n;
  while(n--){
    cin >> num;
    v.push_back(num);
  }
  sort(v.rbegin(), v.rend());
  for(int i : v){
    result += i;
    cnt++;
    if(cnt == 3){
      cnt = 0;
      result -= i;
    }
  }
  cout << result;
  return 0;
}