#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n, w[MAX_N], v[MAX_N], W;

int rec(int i, int j){  // i 表示选取的个数，j 表示质量的剩余
    int res;
    if(i == n){
        // 已经没有剩余物品了
        res = 0;
    }
    else if(j < w[i]){
        // 无法再选取这个物品
        res = rec(i+1 ,j);
    }
    else{
        // 挑选和不挑选两种都试一下
        res = max(rec(i+1, j), rec(i+1,j-w[i]) + v[i]);
    }
    return res;
}

void slove(){
    printf("%d\n",rec(0, W));
}

int main(){
    cin >> n;
    cin >> W;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    slove();
    return 0;
}