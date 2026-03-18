#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&a, int distance, int C){
    int count = 1, size_ = a.size(), lastSelectedElement = a[0];
    for(int i = 1; i < size_; ++i){
        if(a[i] - lastSelectedElement >= distance){
            ++count;
            lastSelectedElement = a[i];
            if(count == C) return true;
        }
    }
    return false;
}

int findMaxDistance(vector<int>& a, int minDis, int maxDis, int C){
    int midDis = 0;
     while(minDis < maxDis){
           midDis = minDis + (maxDis - minDis)/2;
        if(check(a, midDis, C)){
             minDis = midDis + 1;
        }else{
            maxDis = midDis;
        }
     }
     return midDis;
}

int main(){
    int T, N, C;
    cin >> T;
    while(T--){
        cin >> N >> C;
        vector<int> x(N);
        for(int i = 0; i < N; ++i){
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int minDis = 0, maxDis = x.back() - x[0];
        cout << findMaxDistance(x, minDis, maxDis, C) << '\n';
    }
}
