#include<bits/stdc++.h>
using namespace std;

int n, k, num, gap;
vector<int> v;
int main(){
  cin >> k;
  for (int i = 1; i <= k; i++){
    gap = 0;
    cin >> n;
    while(n--){
      cin >> num;
      v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++){
      gap = max(gap, v[i] - v[i - 1]);
    }
    cout << "Class " << i << '\n';
    cout << "Max " << v[v.size() - 1] << ", Min " << v[0] << ", Largest gap " << gap << '\n';
    v.clear();
  }
  return 0;
}