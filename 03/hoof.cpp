#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

void dijkstra(const vector<vector<pair<int,int>>>& adj, int src,
              vector<long long>& dist,
              vector<int>& parent,
              vector<int>& step) {

    int V = adj.size();

    dist.assign(V, (1LL<<62));
    parent.assign(V, -1);
    step.assign(V, -1);

    priority_queue<
        pair<long long, pair<int,int>>,
        vector<pair<long long, pair<int,int>>>,
        greater<pair<long long, pair<int,int>>>
    > pq;

    dist[src] = 0;
    step[src] = 0;
    pq.push({0, {0, src}});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        long long d = cur.first;
        int st = -cur.second.first;
        int u = cur.second.second;

        if (d != dist[u] || st != step[u]) continue;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            long long nd = dist[u] + w;
            int ns = step[u] + 1;

            if (nd < dist[v] || (nd == dist[v] && ns > step[v])) {
                dist[v] = nd;
                step[v] = ns;
                parent[v] = u;
                pq.push({nd, {-ns, v}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, d;
    cin >> s >> d;

    vector<vector<int>> edges; // u v w
    int u, v, w;
    int mx = (s > d ? s : d);

    while (cin >> u >> v >> w) {
        edges.push_back({u, v, w});
        if (u > mx) mx = u;
        if (v > mx) mx = v;
    }

    vector<vector<pair<int,int>>> adj(mx + 1);

    for (auto &e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    vector<long long> dist;
    vector<int> parent, step;
    dijkstra(adj, s, dist, parent, step);

    if (d < 0 || d > mx || dist[d] >= (1LL<<61)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    stack<int> path;
    for (int cur = d; cur != -1; cur = parent[cur])
        path.push(cur);

    if (path.top() != s) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    bool first = true;
    while (!path.empty()) {
        if (!first) cout << ' ';
        first = false;
        cout << path.top();
        path.pop();
    }
    cout << "\n";

    return 0;
}

// ahhhhhhhhhhhhhh
// p pun jai rai