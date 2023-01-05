#include <iostream>
#include <algorithm>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};

// 输入
int C[6];
int A;

void solve(){
    int ans = 0;
    for(int i = 5; i >= 0; i--){
        int t = max(A/V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }
    printf("%d\n", ans);
}

int main(){
    for(int i = 0; i < 6; i++){
        cin >> C[i];
    }
    cin >> A;
    solve();
    return 0;
}