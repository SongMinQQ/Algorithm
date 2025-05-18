#include<bits/stdc++.h>
using namespace std;

int a, b, num, cnt;
vector<int> v;
int main(){
  cin >> a >> b;
  for(int i = 0; i < a; i++){
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  int idx1 = 0, idx2 = a - 1;
  while(idx1 < idx2){
    int sum = v[idx1] + v[idx2];
    if(sum >= b){
      cnt++;
      idx1++;
      idx2--;
    }
    else{
      idx1++;
    }
  }
  cout << cnt;
  return 0;
}