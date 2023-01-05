#include <iostream>
using namespace std;
#define MAX_N 100
int a[MAX_N];
int n, k;

// 已经从前 i 项得到了和 sum，对于 i 项之后的进行分支
bool dfs(int i, int sum){
    // 如果前 n 项得到了和 sum，则返回 sum 是否与 k 相等
    if(i == n)  return sum == k;
    // 不加上 a[i]
    if(dfs(i+1, sum)) return true;
    if(dfs(i+1,sum+a[i])) return true;
    return false;
}

void solve(){
    if(dfs(0, 0))   printf("Yes\n");
    else printf("No\n");
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solve();
}