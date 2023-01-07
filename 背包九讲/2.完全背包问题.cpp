/*
每种物品无限可选
f[i] 表示总体积是 i 的情况下, 最大价值是多少

result = max{f[0,...,m]}

for(int i = 0; i < n; i++){
    for(int j = v[i]; j <= m; j++){
        f[j] = max(f[j],f[j-v[i]]+w[i]);
    }
}
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int v, w;
        cin >> v >> w;
        for(int j = v; j <= m; j++)
            f[j] = max(f[j], f[j-v]+w);
    }
    cout << f[m] << endl;
}
