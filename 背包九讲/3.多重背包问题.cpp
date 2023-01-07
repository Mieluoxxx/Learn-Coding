/*

多重背包, 限制使用次数
f[i] 总体积是 i 的情况下，最大价值是多少

for(int i = 0; i < n; i++){
    for(int j = m; j >= v[i]; --j){
        f[j] = max(f[j], f[j-v[i]]+w[i], f[j-2*v[i]]+2*w[i],...);
    }
}

1. f[i] = 0
f[m]

2. f[0] = 0, f[i] = -INF, i != 0
max{f[0,...,m]}

*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int f[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int j = m; j >= v; --j){
            for(int k = 1; k <= s && k * v <= j; k++)
                f[j] = max(f[j], f[j-k*v]+k*w);
        }
    }
    cout << f[m] << endl;
    return 0;
}

/*
cin:
4 5
1 2 3
2 4 1
3 4 3
4 5 2

cout:
10
*/