#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll result;
vector<ll> resultV;
int main(){
  cin >> n;
  vector<ll> liquads(n);
  for(int i = 0;i < n; i++){
    cin >> liquads[i];
  }
  sort(liquads.begin(),liquads.end());
  int idx1 = 0, idx2 = n - 1;
  ll result = liquads[idx1] + liquads[idx2];
  resultV.push_back(liquads[idx1]);
  resultV.push_back(liquads[idx2]);
  while(idx1 != idx2){
    ll sum = liquads[idx1] + liquads[idx2];
    if(abs(sum) - 1000000000 < abs(result) - 1000000000){
      resultV.clear();
      resultV.push_back(liquads[idx1]);
      resultV.push_back(liquads[idx2]);
    }
    result = abs(sum) - 1000000000 > abs(result) - 1000000000 ?  result : sum;
    
    if(sum < 0){
      idx1++;
    }
    else{
      idx2--;
    }
  }
  cout << resultV[0] << ' ' << resultV[1] << '\n';
  return 0;
}