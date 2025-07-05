#include <algorithm>
#include <iostream>
#include <vector>

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
    vector<vector<int>> get_groups() {
        int n = parent.size();
        vector<vector<int>> groups(n);
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }
        vector<vector<int>> res;
        for (auto &g : groups) {
            if (!g.empty()) res.push_back(g);
        }
        return res;
    }
};

void input_vector(vector<int> &V, int C);
void input_edges(vector<pair<int, int>> &E, int K);
vector<vector<int>> groups(const vector<pair<int, int>> &E, int N);
long long unsatisfied(const vector<int> &c, const vector<int> &G);

int main() {
    int N, M, K;
    vector<int> B, G;
    vector<pair<int, int>> E;
    cin >> N >> M >> K;
    input_vector(B, N);
    input_vector(G, M);
    input_edges(E, K);
    auto C = groups(E, N);
    sort(G.begin(), G.end());

    for (auto &c : C) {
        for (size_t i = 0; i < c.size(); i++) {
            c[i] = B[c[i]];
        }
        sort(c.begin(), c.end());
    }

    long long score = 0;
    for (auto &c : C) {
        score += unsatisfied(c, G);
    }
    cout << score << endl;

    return 0;
}
void input_vector(vector<int> &V, int C) {
    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        V.push_back(x);
    }
}
void input_edges(vector<pair<int, int>> &E, int K) {
    for (int i = 0; i < K; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        E.push_back({v1 - 1, v2 - 1});
    }
}
vector<vector<int>> groups(const vector<pair<int, int>> &E, int N) {
    DSU dsu(N);
    for (const auto &e : E) {
        dsu.unite(e.first, e.second);
    }

    return dsu.get_groups();
}
long long unsatisfied(const vector<int> &c, const vector<int> &G) {
    int s_val = c.at((c.size() - 1) / 2);
    auto pos = lower_bound(G.begin(), G.end(), s_val);
    int gula1 = (pos != G.end()) ? *pos : *(pos - 1);

    long long tolerance1 = 0, tolerance2 = 0;
    for (auto c_level : c) tolerance1 += abs(c_level - gula1);
    long long tolerance = tolerance1;

    if (pos != G.begin()) {
        int gula2 = *(pos - 1);
        for (auto c_level : c) tolerance2 += abs(c_level - gula2);
        tolerance = min(tolerance1, tolerance2);
    }

    return tolerance;
}
