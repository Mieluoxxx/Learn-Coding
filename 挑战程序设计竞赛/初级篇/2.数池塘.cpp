#include <iostream>
using namespace std;
#define MAX_N 100
int N, M;
char field[MAX_N][MAX_N+1];

void dfs(int x, int y){ // 现在的坐标
    // 替换
    field[x][y] = '.';
    // 循环遍历
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            // 八个方向移动
            int nx = x + dx, ny = y + dy;
            if(0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny]=='W'){
                dfs(nx, ny);
            }
        }
    }
    return ;
}

void solve(){
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(field[i][j] == 'W'){
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> field[i][j];
        }
    }
    solve();
    return 0;
}
/*
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........WW.
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/