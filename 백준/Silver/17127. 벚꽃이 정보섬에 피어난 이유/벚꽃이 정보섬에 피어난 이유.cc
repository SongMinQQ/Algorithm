#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n, num, result, sum1, sum2, sum3, sum4;
int calRes(vector<int> a, int s, int range){
  int res = a[s];
  for (int i = s + 1; i < a.size() - range; i++){
    res *= a[i];
  }
  return res;
}
int rangeSum(int a){
  int res = 0;
  switch (a)
  {
  case 0:
    res += v[v.size() - 3];
    res += v[v.size() - 2];
    res += v[v.size() - 1];
    return res;
  case 1:
    res += v[0];
    res += v[v.size() - 2];
    res += v[v.size() - 1];
    return res;
  case 2:
    res += v[0];
    res += v[1];
    res += v[v.size()- 1];
    return res;
  case 3:
    res += v[0];
    res += v[1];
    res += v[2];
    return res;
    default:
      return res;
  }
}
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  for (int i = 0; i < 4; i++){
    result = max(calRes(v, i, 3-i) + rangeSum(i), result);
  }
  cout << result;
  return 0;
}