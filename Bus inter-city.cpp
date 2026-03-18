#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, s, e;
    cin >> n >> m;
    vector<int> c(n + 1), d(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> c[i] >> d[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; ++i){
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    vector<vector<pair<int, int>>> superAdj(n + 1);
    for(int u = 1; u <= n; ++u){
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[u] = 0;
        q.push(u);
        while(!q.empty()){
            int curNode = q.front();
            q.pop();
            if(dist[curNode] >= d[u]) continue;
            for(auto &adjacency: adj[curNode]){
                if(dist[adjacency] == -1){
                    dist[adjacency] = dist[curNode] + 1;
                    if(dist[adjacency] <= d[u]) q.push(adjacency);
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            if(dist[i] != -1 && dist[i] <= d[u]){
                superAdj[u].push_back({i, c[u]});
            }
        }
    }
    vector<int> minCost(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    minCost[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [curCost, curNode] = pq.top();
        pq.pop();
        if(curCost > minCost[curNode]) continue;
        for(auto [ajdacency, w]: superAdj[curNode]){
            int newCost = curCost + w;
            if(newCost < minCost[ajdacency]){
                minCost[ajdacency] = newCost;
                pq.push({newCost, ajdacency});
            }
        }
    }
    cout << minCost[n];
}
