#include<bits/stdc++.h>
using namespace std;

int n, M, maxCandidate, sum, solutions;
vector<int> a;

void Try(int xth){
    for(int candidate = 1; candidate <= maxCandidate; ++candidate){
        if(sum + a[xth]*candidate <= M){
            sum += a[xth]*candidate;
            if(xth == n){
                if(sum == M) ++solutions;
            }else{
                if(sum < M){
                    Try(xth + 1);
                }
            }
            sum -= a[xth]*candidate;
        }
    }
}

int main(){
    cin >> n >> M;
    a.resize(n + 1);

    int tmp;
    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        a[i] = tmp;
        if(M/tmp > maxCandidate){
            maxCandidate = M/tmp;
        }
    }
    
    solutions = sum = 0;
    Try(1);
    cout << solutions;
}
