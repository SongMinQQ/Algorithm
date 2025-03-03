#include<bits/stdc++.h>
using namespace std;

int l, c, checkSum;
char a;
const char check[] = {'a','e','i','o','u'};
vector<char> v;
void print(vector<char> result){
  int cnt1 = 0, cnt2 = 0;
  for(int i = 0; i < l; i++){
    int checkBit = 1 << (result[i] - 'a');
    if(checkBit & checkSum)cnt1++;
    else cnt2++;
  }
  if(cnt1 > 0 && cnt2 > 1){
    for(char i : result){
      cout << i;
    }
    cout << '\n';
    return;
  }
  else return;
}
void makeCombi(vector<char> result, int depth){
  if(result.size() == l){
    print(result);
    return;
  }
  for(int i = depth + 1; i < c; i++){
    result.push_back(v[i]);
    makeCombi(result, i);
    result.pop_back();
  }
  return;
}
int main(){
  cin >> l >> c;
  for(int i = 0; i < 5; i++){
    checkSum |= (1 << (check[i] - 'a'));
  }
  for(int i = 0; i < c; i++){
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  vector<char> pass;
  makeCombi(pass, -1);
  return 0;
}