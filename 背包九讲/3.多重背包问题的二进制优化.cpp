/*
v, w

7 
1, 2, 4
0
1
2
3 = 1 + 2
4 = 4
5 = 1 + 4
6 = 2 + 4
7 = 1 + 2 + 4

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2010;

int n, m;
int f[N];

struct Good{
    int v, w;
};

int main(){
    vector<Good> goods;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int k = 1; k <= s; k *= 2){
            s -= k;
            goods.push_back({v*k, w*k});
        }
        if (s > 0) goods.push_back({v*s, w*s});
    }
    for(auto good: goods){
        for(int j = m; j >= good.v; --j){
            f[j] = max(f[j],f[j-good.v]+good.w);
        }
    }
    cout << f[m] << endl;
    return 0;
}
