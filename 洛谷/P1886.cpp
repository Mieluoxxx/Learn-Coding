#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

const int N = 1000010;

int a[N];

deque<int> q;   // 存储的是编号

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++){
        while(!q.empty() && i-q.front()+1>k){   // 毕业
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] > a[i]){    // 比新生弱的当场退役
            q.pop_back();
        }
        q.push_back(i); // 新生入队
        if(i+1>=k){
            cout << a[q.front()] << " ";
        }
    }
    cout << endl;

    q.clear();

    for(int i = 0; i < n; i++){
        while(!q.empty() && i-q.front()+1>k){
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
            
        }
        q.push_back(i);
        if(i+1>=k){
            cout << a[q.front()] << " ";
        }
    }
    cout << endl;
    return 0;

}