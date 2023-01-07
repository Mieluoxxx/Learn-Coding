/*
f[i][j]表示只看前i个物品，总体积是j的情况下，总价值最大是多少

result = max{f[n][0~V]}

f[i][j]:
1. 不选, f[i][j] = f[i-1][j]
2. 选, f[i][j] = f[i-1][j-v[i]]+v[i];

f[i][j] = max{1. 2.}

f[0][0] = 0
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N];
int v[N], w[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= v[i]; --j)
                f[j] = max(f[j],f[j-v[i]] + w[i]);
    
    cout << f[m] << endl;
    return 0;
}