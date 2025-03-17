#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, b, num, MOD = 1000;

vector<vector<ll>> multiply(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
  vector<vector<ll>> C(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
      for (int k = 0; k < n; k++) {
          for (int j = 0; j < n; j++) {
              C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
          }
      }
  }
  return C;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> A, ll exp) {
  vector<vector<ll>> result(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
      result[i][i] = 1;
  }
  
  while(exp > 0) {
      if(exp & 1) {  // 만약 exp가 홀수이면
          result = multiply(result, A);
      }
      A = multiply(A, A);
      exp /= 2;
  }
  return result;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> b;
  vector<vector<ll>> m(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
            m[i][j] %= MOD;
        }
    }
    
    vector<vector<ll>> result = matrixPow(m, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}