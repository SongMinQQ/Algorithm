#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> a;
    for(char i : s){
        if(a.empty()) {a.push(i); continue;}
        if(!a.empty() && a.top() != i)a.push(i);
        else if(!a.empty() && a.top() == i)a.pop();
    }
    if(a.size()) answer = 0;
    else answer = 1;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << a.size() << endl;

    return answer;
}