#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> ranks;
int find(int x) {
    while (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    ranks.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v) continue;
        if (ranks[root_u] > ranks[root_v]) {
            parent[root_v] = root_u;
        } else if (ranks[root_u] == ranks[root_v]) {
            parent[root_v] = root_u;
            ranks[root_u]++;
        } else {
            parent[root_u] = root_v;
        }
    }
}
