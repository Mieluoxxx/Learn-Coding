#include <iostream>
using namespace std;
#define MAX_N 100

int N;
char S[MAX_N+1];

void solve(){
    int a = 0, b = N - 1;
    while(a <= b){
        // 将从左起到从右起的字符串进行比较
        bool left = false;
        for(int i = 0; a + i <= b; i++){
            if (S[a+i] < S[b-i]){
                left = true;
                break;
            }
            else if(S[a+i] > S[b-i]){
                left = false;
                break;
            }
        }
        if(left) putchar(S[a++]);
        else putchar(S[b--]);
    }
    putchar('\n');
}
int main(){
    cin >> N;
    cin >> S;
    solve();
    return 0;
}