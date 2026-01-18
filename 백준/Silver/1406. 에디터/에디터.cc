#include<bits/stdc++.h>
using namespace std;

string line;
int m;
char a, b;
list<char> l;
// void print(){
//   for(char i : l){
//     cout << i;
//   }
//   cout << '\n';
//   return;
// }
int main(){
  cin >> line;
  for(char i : line){
    l.push_back(i);
  }
  list<char>::iterator cur = l.end();
  cin >> m;
  while(m--){
    cin >> a;
    if(a == 'L'){
      if(cur != l.begin())
        cur--;
    }
    if(a == 'D'){
      if(cur != l.end())
        cur++;
    }
    if(a == 'B'){
      if(cur != l.begin()){
        cur--;
        cur = l.erase(cur);
      }
      // print();
    }
    if(a == 'P'){
      cin >> b;
      if(l.empty()){
        l.push_back(b);
        cur = l.end();
      }
      else
      l.insert(cur, b);
    }
  }
  for(char i : l){
    cout << i;
  }
  return 0;
}