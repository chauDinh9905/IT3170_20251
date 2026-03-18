#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K1, K2;
    cin >> N >> K1 >> K2;
    vector<int> d1(N + 1, 0), d0(N + 1, 0);
    d0[0] = d0[1] = d1[0] = 1, d1[1] = 0;

    for(int i = 1; i <= N; ++i){
        d0[i] = d1[i - 1];
        if(i >= K1){
            int tmp2 = (i - K2 > 0) ? i - K2 : 0;
            int tmp1 = i - K1;
            for(int k = tmp2; k <= tmp1; ++k){
                d1[i] += d0[k];
            }
        }
    }

    cout << d1[N] + d0[N];
}
