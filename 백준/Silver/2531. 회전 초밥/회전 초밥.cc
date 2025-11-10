#include<bits/stdc++.h>
using namespace std;

int n, d, k, c, ret;
vector<int> v;
map<int, int> m;
int main(){
  cin >> n >> d >> k >> c;
  v.resize(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  for (int i = 0; i < k; i++){
    m[v[i]]++;
  }
  m[c] = 999999;
  ret = max(ret, (int)m.size());
  int id2 = k - 1;
  for (int i = 0; i < n - 1; i++){
    m[v[i]]--;
    if(m[v[i]] <= 0){
      m.erase(v[i]);
    }
    // id1 = (id1 + 1) % n;
    id2 = (id2 + 1) % n;
    m[v[id2]]+= 1;

    ret = max(ret, (int)m.size());
  }
  cout << ret;
  return 0;
}