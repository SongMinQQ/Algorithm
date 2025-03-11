#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> check;
    for(int i = 0; i < moves.size(); i++){
        int checkNum = 0;
        int checkIdx = moves[i] - 1;
        for(int j = 0; j < board.size(); j++){
            if(board[j][checkIdx] > 0){
                checkNum = board[j][checkIdx];
                board[j][checkIdx] = 0;
                break;
            }
        }
        if(checkNum != 0){
            if(!check.empty() && checkNum == check.top()){
                answer += 2;
                check.pop();
            }
            else check.push(checkNum);
        }
    }
    return answer;
}