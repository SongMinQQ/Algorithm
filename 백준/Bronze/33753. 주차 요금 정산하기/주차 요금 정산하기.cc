#include<bits/stdc++.h>
using namespace std;

int a, b, c;
float t, de;
int main(){
  cin >> a >> b >> c >> t;
  
  if (t <= 30) {
    cout << a << '\n';
  } else {
    int et = t - 30;
    int efu = ceil(et / (double)b);
    int result = a + efu * c;
    cout << result << '\n';
  }

  return 0;
}