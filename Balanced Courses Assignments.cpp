#include<bits/stdc++.h>
using namespace std;

int m, n, minOfMaxLoad;
vector<int> load, sol;
vector<vector<int>> preference, conflict;

bool check(int courseId, int teacherId){
    if(!preference[teacherId][courseId]) return false;
    for(int courseId1 = 1; courseId1 < courseId; ++courseId1){
        if(preference[teacherId][courseId1] && sol[courseId1] == teacherId && conflict[courseId1][courseId]) return false;
    }
    return true;
}

void Try(int courseId){
    for(int teacherId = 1; teacherId <= m; ++teacherId){
        if(check(courseId, teacherId)){
            ++load[teacherId];
            sol[courseId] = teacherId;
            int curMaxLoad = 0;
            for(int i = 1; i <= m; ++i){
                if(load[i] > curMaxLoad){
                    curMaxLoad = load[i];
                }
            }
            if(courseId == n){
                if(curMaxLoad < minOfMaxLoad) minOfMaxLoad = curMaxLoad;
            }else{
                if(curMaxLoad < minOfMaxLoad){
                    Try(courseId + 1);
                }
            }
            --load[teacherId];
            //sol[courseId] = teacherId;
        }
    }
}

int main(){
    cin >> m >> n;
    minOfMaxLoad = INT_MAX;
    load.resize(m + 1, 0), sol.resize(n + 1, 0);
    preference.resize(m + 1, vector<int>(n + 1, 0)), conflict.resize(n + 1, vector<int>(n + 1, 0));
    
    int k, courseId;
    for(int teacherId = 1; teacherId <= m; ++teacherId){
        cin >> k; 
        while(k--){
            cin >> courseId;
            preference[teacherId][courseId] = 1;
        }
    }

    int i, j;
    cin >> k;
    while(k--){
        cin >> i >> j;
        conflict[i][j] = conflict[j][i] = 1;
    }

    Try(1);
    cout << minOfMaxLoad;
}
