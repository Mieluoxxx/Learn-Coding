#include <iostream>
using namespace std;
typedef long long ll;
#define MAX_N 100

int N, L[MAX_N];

void solve(){
    ll ans = 0;

    // 计算直至木板个数为 1 时
    while(N > 1){
        // 求出最短板和次短板
        int mii1 = 0, mii2 = 1;
        if(L[mii1] > L[mii2])   swap(mii1, mii2);

        for(int i = 2; i < N; i++){
            if(L[i] < L[mii1]){
                mii2 = mii1;
                mii1 = i;
            }
            else if(L[i] < L[mii2]){
                mii2 = i;
            }
        }
        int t = L[mii1] + L[mii2];
        ans += t;

        if(mii1 == N - 1)   swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[N-1];
        N--;
    }
    printf("%lld\n",ans);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> L[i];
    }
    solve();
    return 0;
}





// 贪心算法 哈夫曼树
// 将切割问题转化为拼接问题，每次取出最小的两个之和