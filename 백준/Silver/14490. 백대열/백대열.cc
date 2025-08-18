#include<bits/stdc++.h>
using namespace std;

string a;

vector<string> split(string input, string delimiter){
  vector<string> ret;
  long long pos;
  string token ="";
  while((pos = input.find(delimiter)) != string::npos){
    token = input.substr(0,pos);
    ret.push_back(token);
    input.erase(0, pos + delimiter.length());
  }
  ret.push_back(input);
  return ret;
}

int gcd(int a, int b){
  if(b == 0)
    return a;
    return gcd(b, a % b);
}
int main(){
  cin >> a;
  vector<string> numArr = split(a, ":");
  int num1 = stoi(numArr[0]), num2 = stoi(numArr[1]);
  if (num2 < 0) { num1 = -num1; num2 = -num2; }
  int g = gcd(num1, num2);
  if (g == 0) {
        cout << "0:0";
    } else {
        cout << num1 / g << ":" << num2 / g;
    }
  return 0;
}