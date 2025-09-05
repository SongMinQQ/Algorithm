#include<bits/stdc++.h>
using namespace std;

int n, num, result, L[1002];

int main(){
  cin >> n;
  while(n--){
    cin >> num;
    auto pos = lower_bound(L + 1, L + result + 1,num);
    *pos = num;
    if (pos == L + result + 1)result++;
  }
  cout << result;
  return 0;
}