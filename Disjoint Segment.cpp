#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> x;
    int a, b, n;
    cin >> n;
    while(n--){
        cin >> a >> b;
        x.push_back({a, b});
    }
    sort(x.begin(), x.end(), [](pair<int, int>&x1, pair<int, int>x2){return x1.second > x2.second;});

    int count = 0, last = -1;
    while(!x.empty()){
        pair<int, int> p = x.back();
        x.pop_back();
        if(p.first > last){
            ++count;
            last = p.second;
        }
    }

    cout << count;
}
