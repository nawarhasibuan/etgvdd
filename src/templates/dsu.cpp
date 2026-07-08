#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
    vector<vector<int>> groups() {
        vector<vector<int>> temp(parent.size());
        // masukkan tiap vertex ke kelompok root nya
        for (int i = 0; i < parent.size(); i++) {
            // cari root
            int root = find(i);
            // masukkan i ke kelompok root
            temp[root].push_back(i);
        }
        // tiap vertex terkelompok root masing-masing
        // ada kemungkinan yang kosong
        // ukuran sebanyak kelompok yang ada, beda tiap input berbeda
        vector<vector<int>> result;
        // ambil yang tidak kosong temp
        for (auto group : temp) {
            // masukkan ke result jika tidak kosong
            if (!group.empty()) {
                result.push_back(group);
            }
        }
        return result;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr = vector(20, 9);
    auto dsu = DSU(n);
    // input edge/sisi
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }
    // perent representasi dari tree yang saling terhubung
    vector<vector<int>> groups = dsu.groups();

    return 0;
}
