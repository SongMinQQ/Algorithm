#include<bits/stdc++.h>
using namespace std;
const int comp1[] = {1, 2, 3, 4, 5, 6, 7, 8};
const int comp2[] = {8, 7 ,6, 5, 4, 3, 2, 1};
int a[8];
int main(){
  for (int i = 0; i < 8; i++){
    cin >> a[i];
  }
  if (equal(a, a+8, comp1))
    cout << "ascending";
  else if (equal(a, a+8, comp2))
    cout << "descending";
  else
    cout << "mixed";
  return 0;
}