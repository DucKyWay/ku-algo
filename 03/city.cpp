#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

static void build_finish_order(int V, const vector<vector<int>>& g, vector<int>& order) {
    vector<char> visited(V + 1, 0);
    order.clear();
    order.reserve(V);

    for (int s = 1; s <= V; s++) {
        if (visited[s]) 
            continue;

        vector<pair<int,int>> st;
        st.push_back({s, 0});
        visited[s] = 1;

        while (!st.empty()) {
            int u = st.back().first;
            int& ax = st.back().second;

            if (ax < (int)g[u].size()) {
                int v = g[u][ax++];
                if (!visited[v]) {
                    visited[v] = 1;
                    st.push_back({v, 0});
                }
            } else {
                order.push_back(u);
                st.pop_back();
            }
        }
    }
}

static int scc_size_from(int s, const vector<vector<int>>& gr, vector<char>& seen) {
    int cnt = 0;
    stack<int> st;
    st.push(s);
    seen[s] = 1;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        cnt++;

        for (int v : gr[u]) {
            if (!seen[v]) {
                seen[v] = 1;
                st.push(v);
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> g(V + 1), gr(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<int> order;
    build_finish_order(V, g, order);

    vector<char> seen(V + 1, 0);
    vector<int> sizes;
    sizes.reserve(V);

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int s = order[i];
        if (seen[s]) continue;
        sizes.push_back(scc_size_from(s, gr, seen));
    }

    sort(sizes.begin(), sizes.end(), greater<int>());
    while ((int)sizes.size() < 5) 
        sizes.push_back(0);

    for (int i = 0; i < 5; i++) {
        if (i)
            cout << ",";
        cout << sizes[i];
    }
    cout << "\n";
    return 0;
}

// 💀💀💀💀💀💀 OMG p'pond