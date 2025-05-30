#include<bits/stdc++.h>
using namespace std;

int n, m, num;
vector<int> v;
int binary_search(int len, int t){
  int low = 0, high = len - 1;
  int result = -1;

  while(low <= high){
      int mid = (low + high) / 2;
      if(v[mid] == t){
          result = mid;
          high = mid - 1;
      }
      else if(v[mid] < t){
          low = mid + 1;
      }
      else {
          high = mid - 1;
      }
  }
  return result;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++){
    cin >> num;
    cout << binary_search(v.size(), num) << '\n';
  }
  return 0;
}