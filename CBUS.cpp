#include<bits/stdc++.h>
using namespace std;

int n, size_, load, curDistance, minDistance, cMin, k;
vector<int> path, visited;
vector<vector<int>> c;

bool check(int stationId){
    if(visited[stationId]) return false;
    if(stationId <= n){
        if(load + 1 > k) return false;
    }else{
        if(!visited[stationId - n]) return false;
    }
    return true;
}

void Try(int ithStation){
    for(int stationId = 1; stationId < size_; ++stationId){
        if(check(stationId)){
            if(stationId > n) --load;
            else ++load;
            curDistance += c[path[ithStation - 1]][stationId];
            path[ithStation] = stationId;
            visited[stationId] = 1;

            if(ithStation == size_ - 1){
                int total = curDistance +  c[stationId][0];
                if(total < minDistance) minDistance = total;
            }else{
                if(curDistance + cMin*(size_ - ithStation) < minDistance){
                    Try(ithStation + 1);
                }
            }
            if(stationId > n) ++load;
            else --load;
            curDistance -= c[path[ithStation - 1]][stationId];
            //path[ithStation] = stationId;
            visited[stationId] = 0;
        }
    }
}

int main(){
    cin >> n >> k;
    size_ = 2*n + 1;
    load = curDistance = 0, minDistance = cMin = INT_MAX;
    path.resize(size_), visited.resize(size_, 0);
    c.resize(size_, vector<int>(size_));
    path[0] = 0, visited[0] = 1;

    int tmp;
    for(int i = 0; i < size_; ++i){
        for(int j = 0; j < size_; ++j){
            cin >> tmp;
            c[i][j] = tmp;
            if(i != j){
                if(cMin > tmp) cMin = tmp;
            }
        }
    }

    Try(1);
    cout << minDistance;
}
