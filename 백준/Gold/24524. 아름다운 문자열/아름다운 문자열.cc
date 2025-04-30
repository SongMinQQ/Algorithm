#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string S, T;
  cin >> S >> T;
  int n = S.size(), m = T.size();
  vector<int> idx(26, -1);
  for(int i = 0; i < m; i++){
    idx[T[i] - 'a'] = i;
  }
  vector<long long> cnt(m, 0);
  long long answer = 0;

  for(char c : S){
    int p = idx[c - 'a'];
    if(p < 0) continue;

    if(p == 0){
      if(m == 1) {
        answer++;
      } else {
        cnt[1]++;
      }
    } else {
      if(cnt[p] > 0){
        cnt[p]--;
        if(p + 1 == m){
          answer++;
        } else {
          cnt[p+1]++;
        }
      }
    }
  }

  cout << answer << "\n";
  return 0;
}
