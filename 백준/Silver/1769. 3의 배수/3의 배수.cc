#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string line, ret;
int cnt;
int main(){
  cin >> line;
  int a = 0;
  for(char c : line){
    a += c - '0';
  }
  ret = a % 3 == 0 ? "YES" : "NO";
  while(line.size() != 1){
    long long sum = 0;
    for (char c : line) sum += c - '0';
    line = to_string(sum);
    cnt++;
  }
  cout << cnt << '\n' << ret;
  return 0;
}