#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, ik, jk, Q = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int size_ = log2(n) + 1;
    vector<vector<int>> M(size_, vector<int>(n));

    for(int i = 0; i < n; ++i){
        M[0][i] = i;
    }

    for(int i = 1; i < size_; ++i){
        int tmp = (1 << i) - 1;
        for(int j = 0; j + tmp < n; ++j){
            int left = M[i - 1][j], right = M[i - 1][j + (1 << (i - 1))];
            M[i][j] = (a[left] < a[right]) ? left : right;
        }
    }

    cin >> m;
    while(m--){
        cin >> ik >> jk;
        int k = log2(jk - ik + 1);
        int mid = jk - (1 << k) + 1, left = M[k][ik], right = M[k][mid];
        if(a[left] < a[right]){
            Q += a[left];
        }else{
            Q += a[right];
        }
    }

    cout << Q;
}
