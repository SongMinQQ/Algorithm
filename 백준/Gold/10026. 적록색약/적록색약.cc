#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[104][104];
bool visited[104][104];
int n, result1, result2;

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || a[y][x] != a[ny][nx]) continue;
        dfs(ny, nx);
    }
}
void dfs2(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(a[y][x] != 'B' && a[ny][nx] == 'B') continue;
        if(a[y][x] == 'B' && a[ny][nx] != 'B') continue;
        dfs2(ny, nx);
    }
}
int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0){
                dfs(i,j);
                result1++;
            }
        }
    }
    fill(visited[0],visited[0]+104*104, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0){
                dfs2(i,j);
                result2++;
            }
        }
    }
    cout << result1 << ' ' << result2;
    return 0;
}