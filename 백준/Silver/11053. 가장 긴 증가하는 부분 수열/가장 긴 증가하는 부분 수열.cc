#include<bits/stdc++.h>
using namespace std;

int num[1002], len[1002], n, result = 0;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num[i];
  }
  for(int i = 0; i < n; i++){
    len[i] = 1;
    for(int j = 0; j < n; j++){
      if(num[i] > num[j]) len[i] = max(len[i], len[j] + 1);
    }
  }
  for(int i = 0; i < n; i++){
    if(len[i] > result) result = len[i];
  }
  cout << result;
  return 0;
}