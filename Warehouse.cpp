#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, T, D, result = 0;
    cin >> N >> T >> D;
    vector<int> a(N + 1), t(N + 1);
    vector<vector<int>> f(N + 1, vector<int>(T + 1));

    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= N; ++i){
        cin >> t[i];
    }

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= T; ++j){
            if(j < t[i]) f[i][j] = 0;
            else{
                int remainingTime = j - t[i];
                int tmp = 0, tmp1 = (i - D > 0) ? i - D : 0, tmp2 = i - 1;
                for(int k = tmp1; k <= tmp2; ++k){
                    tmp = max(tmp, f[k][remainingTime]);
                }
                f[i][j] = tmp + a[i];
                result = max(result, f[i][j]);
            }
        }
    }
    cout << result;
}
