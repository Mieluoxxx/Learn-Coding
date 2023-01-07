#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int a, b, n;
int c[N][N], mx[N][N], mn[N][N];

int main(){
    cin >> a >> b >> n;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= a; i++){
        // 在第 i 行进行利用单调队列求窗口最大值的过程
        deque<int> q;
        for(int j = 1; j <= b; j++){
            if(!q.empty() && j - q.front() >= n)    
                q.pop_front();
            while(!q.empty() && c[i][j] >= c[i][q.back()]) q.pop_back();
            q.push_back(j);
            if(j >= n)  mx[i][j-n+1] = c[i][q.front()];
        }
    }

    for(int j = 1; j <= b; j++){
        // 在第 j 列进行利用单调队列求窗口最大值的过程
        deque<int> q;
        for(int i = 1; i <= a; i++){
            if(!q.empty() && i - q.front() >= n)    
                q.pop_front();
            while(!q.empty() && mx[i][j] >= mx[q.back()][j]) q.pop_back();
            q.push_back(i);
            if(i >= n)  mx[i-n+1][j] = mx[q.front()][j];
        }
    }

    for(int i = 1; i <= a; i++){
        // 在第 i 列进行利用单调队列求窗口最小值的过程
        deque<int> q;
        for(int j = 1; j <= b; j++){
            if(!q.empty() && j - q.front() >= n)    
                q.pop_front();
            while(!q.empty() && c[i][j] <= c[i][q.back()]) q.pop_back();
            q.push_back(j);
            if(j >= n)  mn[i][j-n+1] = c[i][q.front()];
        }
    }

    for(int j = 1; j <= b; j++){
        // 在第 j 列进行利用单调队列求窗口最小值的过程
        deque<int> q;
        for(int i = 1; i <= a; i++){
            if(!q.empty() && i - q.front() >= n)    
                q.pop_front();
            while(!q.empty() && mn[i][j] <= mn[q.back()][j]) q.pop_back();
            q.push_back(i);
            if(i >= n)  mn[i-n+1][j] = mn[q.front()][j];
        }
    }

    int ans = 1e9;
    for(int i = 1; i <= a-n+1; i++){
        for(int j = 1; j <= b-n+1; j++){
            ans = min(ans, mx[i][j] - mn[i][j]);
        }
    }

    cout << ans;
    return 0;
}