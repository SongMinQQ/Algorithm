#include<bits/stdc++.h>
using namespace std;

string line;
int n;
int main(){
  cin >> n;
  while(n--){
    cin >> line;
    int cnt = 0, result = 0;
    for(char i : line){
      i == 'O' ? cnt++ : cnt = 0;
      result += cnt;
    }
    cout << result << '\n';
  }
  return 0;
}