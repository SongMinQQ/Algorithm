#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  vector<long long> nums(T);
  long long maxK = 0;

  for (int i = 0; i < T; ++i){
    cin >> nums[i];
    if (nums[i] % 2 == 0){
      maxK = max<long long>(maxK, nums[i] / 2);
    }
  }

  vector<ll> C(maxK + 1, 0);
  C[0] = 1;
  for (long long n = 1; n <= maxK; ++n){
    ll acc = 0;
    for (long long i = 0; i <= n - 1; ++i){
      acc = (acc + C[i] * C[n - 1 - i]) % MOD;
    }
    C[n] = acc;
  }

  for (int i = 0; i < T; ++i){
    long long N = nums[i];
    if (N % 2 == 1){
      cout << 0 << '\n';
    }
    else{
      cout << C[N / 2] << '\n';
    }
  }
  return 0;
}
