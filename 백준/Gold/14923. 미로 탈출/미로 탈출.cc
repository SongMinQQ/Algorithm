#include <bits/stdc++.h>
using namespace std;

static const int MAX = 1002;

int n, m;
int hx, hy, ex, ey, cy, cx, w;         
int maze[MAX][MAX];         
int visited[MAX][MAX][2];   

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> hx >> hy >> ex >> ey;
    hx--, hy--;
    ex--, ey--;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    queue< tuple<int,int,int> > q;

    visited[hx][hy][0] = 1;
    q.push({hx, hy, 0}); 

    while(!q.empty()){
        tie(cy, cx, w) = q.front();
        q.pop();

        if(cy == ex && cx == ey){
            cout << visited[cy][cx][w] - 1 << "\n";
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if(maze[ny][nx] == 0){
                if(visited[ny][nx][w] == 0){
                    visited[ny][nx][w] = visited[cy][cx][w] + 1;
                    q.push({ny, nx, w});
                }
            }
            else {
                if(w == 0 && visited[ny][nx][1] == 0){
                    visited[ny][nx][1] = visited[cy][cx][0] + 1; 
                    q.push({ny, nx, 1});
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
