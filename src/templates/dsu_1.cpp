#include <bits/stdc++.h>

using namespace std;

void unite(int u, int v, vector<int> &parent);
int find_root(int vertex, vector<int> &parent);
vector<vector<int>> dsu(vector<int> &parent);

int main() {
    // n: banyak vertex, m: banyak edge(sisi)
    int n, m;
    cin >> n >> m;

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // input edge/sisi
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v, parent);
    }
    // perent representasi dari tree yang saling terhubung
    vector<vector<int>> groups = dsu(parent);
    return 0;
}

void unite(int u, int v, vector<int> &parent) {
    int root_u = find_root(u, parent);
    int root_v = find_root(v, parent);
    if (root_u == root_v) return; // u dan v sudah di kelompok yang sama
    // gabungkan root_u dan root_v
    parent[root_v] = root_u; // root_v menjadi anak dari root_u
}
int find_root(int vertex, vector<int> &parent) {
    // root adalah vertex yang parentnya dirinya sendiri
    while (vertex != parent[vertex]) {
        vertex = parent[vertex];
    }
    // vertex == parent[vertex]
    return vertex;
}

vector<vector<int>> dsu(vector<int> &parent) {
    vector<vector<int>> temp(parent.size());
    // masukkan tiap vertex ke kelompok root nya
    for (int i = 0; i < parent.size(); i++) {
        // cari root
        int root = find_root(i, parent);
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
