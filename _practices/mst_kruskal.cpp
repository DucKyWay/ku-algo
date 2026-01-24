#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;
};

int find(int i, DSU &dsu) {
    // return (dsu.parent[i] == i) ? i : (dsu.parent[i] = find(dsu.parent[i], dsu));
    if(dsu.parent[i] == i) {
        return i;
    } else {
        dsu.parent[i] = find(dsu.parent[i], dsu);
        return dsu.parent[i];
    }
}

void unite(int x, int y, DSU &dsu) {
    int s1 = find(x, dsu), s2 = find(y, dsu);
    if(s1 != s2) {
        if(dsu.rank[s1] < dsu.rank[s2]) dsu.parent[s1] = s2;
        else if(dsu.rank[s1] > dsu.rank[s2]) dsu.parent[s2] = s1;
        else dsu.parent[s2] = s1, dsu.rank[s1]++;
    }
}

bool comparator(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

/* ===== Kruskal ===== */

int kruskal(int V, vector<vector<int>> &edges) {

    sort(edges.begin(), edges.end(), comparator);

    DSU dsu;
    dsu.parent.resize(V);
    dsu.rank.resize(V);
    for(int i = 0; i < V; i++) {
        dsu.parent[i] = i;
        dsu.rank[i] = 1;
    }
    int cost = 0, count = 0;

    for(auto &e : edges) {
        int x = e[0], y = e[1], w = e[2];

        if(find(x, dsu) != find(y, dsu)) {
            unite(x, y, dsu);
            cost += w;
            if(++count == V - 1) {
                break;
            }
        }
    }

    return cost;
}

int main() {

    vector<vector<int>> edges = {
        {0, 1, 10}, 
        {1, 3, 15}, 
        {2, 3, 4}, 
        {2, 0, 6}, 
        {0, 3, 5}
    };
    
    cout << "Mininum cost spanning tree: " << kruskal(4, edges);

    return 0;
}