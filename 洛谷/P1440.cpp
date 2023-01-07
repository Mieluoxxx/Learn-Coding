#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

const int N = 2000010;

int a[N];

deque<int> q;   // 存储的是编号

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> a[i];
    cout << "0" << "\n";

    for(int i = 0; i < n-1; i++){
        while(!q.empty() && i-q.front()+1>m){   // 毕业
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] > a[i]){    // 比新生弱的当场退役
            q.pop_back();
        }
        q.push_back(i); // 新生入队
        cout << a[q.front()] << "\n";
    }
    return 0;
}