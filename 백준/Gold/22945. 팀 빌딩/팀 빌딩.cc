#include<bits/stdc++.h>
using namespace std;

int n, num, result;
vector<int> v;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  int p1 = 0, p2 = n - 1;
  while(p1 <= p2){
    int humans = p2 - (p1 + 1);
    int stat = humans * min(v[p1],v[p2]);
    result = max(result, stat);
    if(v[p1] < v[p2]){
      p1++;
    }
    else
      p2--;
  }
  cout << result;
  return 0;
}