#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
0에 가까운 값을 확인하려면?
일단 두 값 더하면 절대값으로 바꾸고 1억이랑 나눈 나머지값 확인해볼까
해보면 될듯
생각해보니까 잘못하면 2억 3억같은 값이 답이될수도 있을듯
정렬된 거니까 0보다 큰지 작은지로 판단하면 될듯 음수가 나올수 있고 양수가 나올수 있음
*/

int n;
ll result;
int main(){
  cin >> n;
  vector<ll> liquads(n);

  for(int i = 0;i < n; i++){
    cin >> liquads[i];
  }
  int idx1 = 0, idx2 = n - 1;
  ll result = liquads[idx1] + liquads[idx2];
  while(idx1 != idx2){
    ll sum = liquads[idx1] + liquads[idx2];
    result = abs(sum) - 100000000 > abs(result) - 100000000 ?  result : sum;
    if(sum < 0){
      idx1++;
    }
    else{
      idx2--;
    }
  }
  cout << result << '\n';
  return 0;
}