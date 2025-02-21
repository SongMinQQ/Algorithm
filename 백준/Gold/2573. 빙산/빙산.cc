#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, a[302][302], curY, curX, cnt = 0, result = 0;
bool visited[302][302];
int meltCnt[302][302] = {0};
queue<pair<int,int>> q;

void bfs(int y, int x){
    q.push({y, x});
    while(!q.empty()){
        tie(curY, curX) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == 0) meltCnt[curY][curX] += 1;
            if(visited[ny][nx] == 1) continue;
            if(a[ny][nx] > 0 && visited[ny][nx] == 0){ 
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}
void melt(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = max(0, a[i][j] -= meltCnt[i][j]);
        }
    }
}
bool isIceMelt(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] > 0) return false;
        }
    }
    return true;
}
int main(){
    fill(&meltCnt[0][0], &meltCnt[301][302], 0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    while(1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > 0 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        melt();
        if(cnt > 1) break;
        cnt = 0;
        result++;
        if(isIceMelt()){
            result = 0; break;
        }
        
        fill(&visited[0][0], &visited[301][302], 0);
        fill(&meltCnt[0][0], &meltCnt[301][302], 0);
    }
    cout << result;
    return 0;
}