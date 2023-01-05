#include <iostream>
using namespace std;
const int MAX_N = 10000;

int N, S[MAX_N], T[MAX_N];
pair<int, int> itv[MAX_N];

void solve(){
    // 对pair进行的是字典序比较
    // 为了让结束时间早的工作排在前面，把 T 存入first, 把S存入second
    for (int i = 0; i < N; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + N);

    // t 是最后所选工作的结束时间
    int ans = 0, t = 0;
    for(int i = 0; i < N; i++){
        if(t < itv[i].second){
            ans++;
            t = itv[i].first;
        }
    }
    printf("%d\n", ans);
}

int main(){
    cin >> N;
    for (int i = 0; i < 5; i++){
        cin >> S[i];
    }
    for (int i = 0; i < 5; i++){
        cin >> T[i];
    }
    solve();
    return 0;
}