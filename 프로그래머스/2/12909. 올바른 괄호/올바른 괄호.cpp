#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        if(s[i] == ')'){
            if(st.empty()) return false;
            st.pop();
        }
    }
    if(st.empty()) return answer;
    else return false;
}