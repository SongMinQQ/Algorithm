#include <bits/stdc++.h>
using namespace std;
const int INF = 999999999;
int n, k, cnt, a[102];
bool use[102];
vector<int> v;

int main(){
    cin >> k >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
      if(!use[a[i]]){
        if(v.size() == k){
          int last_idx = -1, pos = -1;
          for(int j : v){
            int here_idx = INF;
            for(int l = i + 1; l < n; l++){
              if(j == a[l]){
                here_idx = l;
                break;
              }
            }
            if(here_idx > last_idx){
              last_idx = here_idx;
              pos = j;
            }
          }
          use[pos] = false;
          cnt++;
          v.erase(find(v.begin(), v.end(), pos));
        }
        v.push_back(a[i]);
        use[a[i]] = true;
      }
    }
    
    cout << cnt << '\n';
    return 0;
}
