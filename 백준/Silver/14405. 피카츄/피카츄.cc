#include <bits/stdc++.h>

using namespace std;

// vector<string> split(string input, string delimiter){
//     vector<string> ret;
//     long long pos = 0;
//     string token = "";
//     //find 함수로 찾은 문자가 delimiter와 같을 때까지 반복
//     //pos에는 찾은 문자열이 시작하는 index 반환
//     while((pos = input.find(delimiter)) != string::npos){
//         token = input.substr(0,pos);
//         ret.push_back(token);
//         //erase함수로 0부터 찾은 문자열이 시작하는 index + 나누려는 문자열의 길이의 이전 index만큼 없앰
//         input.erase(0,pos + delimiter.length());
//     }
//     ret.push_back(input);
//     return ret;
// }

string S, check;

int main(){
  cin >> S;
  while(!(S.length() == 0)){
    string check1 = S.substr(0,2);
    string check2 = S.substr(0,3);
    // cout << "check1 : " << check1 << " check2 : " << check2 << '\n';
    if(check1 == "pi" || check1 == "ka") S=S.substr(2, S.length());
    else if (check2 == "chu")
    {
      /* code */
      S=S.substr(3,S.length());
    }
    else {cout << "NO\n"; return 0;}
  }
  cout << "YES\n";
  return 0;
}