#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> qu;
int y, x, visited[6][6];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int bfs(vector<string> v, queue<pair<int,int>> q){
    while(!q.empty()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || v[ny][nx] == 'X' || visited[ny][nx] > 0) continue;
            if(v[ny][nx] == 'P' && visited[y][x] < 3) {
                // cout << "--------\n" << y << ' ' << x << ' ' << visited[y][x] << '\n' << ny << ' ' << nx << ' '<< visited[ny][nx] << "\n---------\n";
                fill(&visited[0][0], &visited[0][0] + 36, 0);
                return 0;
            }
            else if(v[ny][nx] == 'P'){
                fill(&visited[0][0], &visited[0][0] + 36, 0);
                return 1;
                // visited[ny][nx] = 1;
                // while(!q.empty())q.pop();
                // q.push({ny,nx});
            }
            else {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); i++){
        int result = 1;
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(places[i][j][k] == 'P'){
                    while(!qu.empty()) qu.pop();
                    visited[j][k] = 1;
                    qu.push({j, k});
                    result = min(bfs(places[i], qu), result);
                }
            }
        }
        answer.push_back(result);
        fill(&visited[0][0], &visited[0][0] + 36, 0);
        
    }
    return answer;
}