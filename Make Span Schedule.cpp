#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, s, e, res = 0;
    cin >> n >> m;
    vector<int> dist(n + 1), dad(n + 1), d(n + 1);
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> d[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> s >> e;
        adj[s].push_back(e);
        dad[e]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(dad[i] == 0){
            dist[i] = d[i];
            q.push(i);
        }
    }
    while(!q.empty()){
        int curNode = q.front();
        q.pop();
        for(auto &adjacency: adj[curNode]){
            dist[adjacency] = max(dist[adjacency], dist[curNode] + d[adjacency]);
            dad[adjacency] -= 1;
            if(dad[adjacency] == 0) q.push(adjacency);
        }
    }
    for(int i = 1; i <= n; ++i){
        if(res < dist[i]) res = dist[i];
    }
    cout << res;
}
