#include<bits/stdc++.h>
using namespace std;

int n, num;
map<int, int> m;
int main(){
  cin >> n;
  while(n--){
    cin >> num;
    m[num]++;
  }
  for(auto i : m){
    cout << i.first << ' ';
  }
  return 0;
}