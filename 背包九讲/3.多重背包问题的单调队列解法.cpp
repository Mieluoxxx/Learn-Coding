#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010;

int n, m;
int f[N], g[N], q[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int c, w, s;
        cin >> c >> w >> s;
        memcpy(g, f, sizeof(f));
        for(int j =0; j < c; j++){
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += c){
                f[k] = g[k];
                if(hh <= tt && k-s*c>q[tt]) hh++;
                if(hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / c * w);
                while(hh <= tt && g[q[hh]] - (q[tt]-j)/c*w<=g[k]-(k-j)/c*w) tt--;
                q[++tt] = k;
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}