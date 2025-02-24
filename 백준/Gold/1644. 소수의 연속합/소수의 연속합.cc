#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> sosu;
int n, result;
bool isPrime[5000000];
void check(){
  fill(isPrime, isPrime + 5000000, true);
  isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님
  // 에라토스테네스의 체
  for (ll i = 2; i * i < 5000000; i++) {
    if (isPrime[i]) {
        for (ll j = i * i; j < 5000000; j += i) {
            isPrime[j] = false;
        }
    }
  }
}
int main(){
  /*
  400만까지의 소수 배열을 만든다. 어케? 2부터 400만까지 for문돌려서 소수조건 충족하면 push
  */
  check();
  for(int i = 2; i < 5000000; i++){
    if(isPrime[i]) sosu.push_back(i);
  }
  cin >> n;
  int cnt = 0;
  int idx1 = 0, idx2 = 0;
  ll sum = 0;
  while(1){
    // if(sosu[idx1] == n) {cnt++; break;}
    if (sum >= n) {
      if (sum == n) cnt++;
      sum -= sosu[idx1++];
  } else {
      if (idx2 == sosu.size()) break;
      sum += sosu[idx2++];
  }
  }
  cout << cnt << '\n';
  return 0;
}
