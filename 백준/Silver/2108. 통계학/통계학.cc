#include<bits/stdc++.h>
using namespace std;

double n, sum, mx = -4001, mi = 4001, num;
map<double, double> mp;
vector<double> v, keys;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> num;
    sum += num;
    mp[num]++;
    if(mp[num] != 0) v.push_back(num);
    mx = num > mx ? num : mx;
    mi = num < mi ? num : mi;
  }
  double maxValue = max_element(mp.begin(), mp.end(),
    [](const pair<double, double> &a, const pair<double, double> &b)
    {
      return a.second < b.second;
    })
    ->second;
  for (auto &p : mp){
    double key = p.first;
    double value = p.second;
    if (value == maxValue)
    {
      keys.push_back(key);
    }
  }
  int choiBinGap;
  if ((int)keys.size() != 1)
    choiBinGap = keys[1];
  else choiBinGap = keys[0];
  sort(v.begin(), v.end());
  cout << floor(sum / n + 0.5) << '\n'
       << v[floor(n / 2)] << '\n'
       << choiBinGap << '\n'
       << mx - mi;
  return 0;
}