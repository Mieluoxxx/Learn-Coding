#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100
#define MAX_M 100
const int INF = 1000000;

// 使用 pair 表示状态时，使用 typedef 会更方便
typedef pair<int, int> P;

char maze[MAX_N][MAX_M];
int N, M;   // 加载地图
int sx, sy; // 开始坐标
int gx, gy; // 重点坐标

int d[MAX_N][MAX_M]; // 到各个位置的最短距离的数组

// 4个方向移动的向量
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

// 求从（sx, sy）到（gx, gy）的最短距离
// 如果无法到达，则 INF
int bfs(){
    queue<P> que;
    // 把所有的位置都初始化为INF
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    // 不断循环直到队列的长度为0
    while(que.size()){
        // 从队列的最前端取出元素
        P p = que.front(); que.pop();
        // 如果取出的状态已经是终点，则结束搜索
        if(p.first == gx && p.second == gy) break;

        // 从四个方向的循环
        for(int i = 0; i < 4; i++){
            // 移动之后的位置记为(nx, ny)
            int nx = p.first + dx[i], ny = p.second + dy[i];

            // 判断是否可以移动以及是否已经访问过(d[nx][ny]!=INF即为已经访问过)
            if(0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' &&
                d[nx][ny] == INF){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

void solve(){
    int res = bfs();
    printf("%d\n", res);
}
int main(){
    cin >> N >> M;
    cout << "输入开始坐标" << "\n";
    cin >> sx >> sy;
    cout << "输入结束坐标" << "\n";
    cin >> gx >> gy;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> maze[i][j];
        }
    }
    solve();
    return 0;
}

/*
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/