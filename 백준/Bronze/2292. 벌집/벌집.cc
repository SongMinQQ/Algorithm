#include <bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
  cin >> n;
  if (n==1)
  {
    cout << 1;
    return 0;
  }
  n--;
  for (int i=6; n>0; i+=6)
  {
    n-=i;
    x=i/6;
  }
  cout << x + 1;
  return 0;
}