#include <bits/stdc++.h>
using namespace std;

int n, idx1, idx2, target, cnt, num, sum;
set<int> s;
vector<int> v;
int main()
{
  cin >> n;
  idx2 = n - 1;
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    v.push_back(num);
    s.insert(num);
  }
  // int target;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    idx1 = 0;
    idx2 = n - 1;
    target = v[i];
    while (idx2 > idx1)
    {
      sum = v[idx1] + v[idx2];
      if (sum == target){
        if (idx1 == i){
          idx1++;
        }
        else if (idx2 == i){
          idx2--;
        }
        else{
          // cout << v[idx1] << " " << v[idx2] << " " << target << '\n';
          cnt++;
          s.erase(target);
          break;
        }
      }
      else{
        if (sum > target){
          idx2--;
        }
        else idx1++;
      }
    }
  }
  cout << cnt;
  return 0;
}