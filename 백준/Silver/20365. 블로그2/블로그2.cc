#include<bits/stdc++.h>
using namespace std;

int n, cnt1, cnt2;
string a;
char b, c;
int main(){
  cin >> n >> a;
  int blue = 0, red = 0;
  if (a[0] == 'B')
    blue++;
  else
    red++;
  for (int i = 1; i < n; i++)
  {
    if (a[i] != a[i - 1])
    {
      if (a[i] == 'B')
        blue++;
      else
        red++;
    }
  }
  cout << 1 + min(blue, red) << '\n';
  return 0;
}