#include<bits/stdc++.h>
using namespace std;

int curNum, numOfBridge, articulation;
vector<int> low, num;
vector<vector<int>> adj;
vector<bool> joint;

void Analyze(int v, int parentV){
   int child = 0;
   low[v] = num[v] = curNum++;
   for(auto &u: adj[v]){
      if(u == parentV) continue;
      if(num[u] == -1){
        ++child;
        Analyze(u, v);
        low[v] = min(low[u], low[v]);
        if((parentV == -1 && child > 1) || (parentV != -1 && low[u] >= num[v])){
            joint[v] = true;
        }
        if(low[u] > num[v]) ++numOfBridge;
      }else{
        low[v] = min(num[u], low[v]);
      }
   }
}

int main(){
    int n, m, s, e;
    cin >> n >> m;
    adj.resize(n + 1);
    low.resize(n + 1); num.resize(n + 1, -1);
    joint.resize(n + 1, false);
    for(int i = 1; i <= m; ++i){
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    curNum = 1, numOfBridge = articulation = 0;
    for(int i = 1; i <= n; ++i){
        if(num[i] == -1){
            Analyze(i, -1);
        }
    }
    for(auto i: joint){
          if(i) ++articulation;
    }
    cout << articulation << ' ' << numOfBridge;
}
