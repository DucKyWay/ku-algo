#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int V = adj.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.emplace(0, src);

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if(d > dist[u]) continue;

        for(auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {
    return 0;
}