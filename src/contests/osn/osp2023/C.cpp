#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<long long>> adj;
vector<long long> a;
vector<long long> b;
vector<long long> kesulitan;
vector<bool> visited;

/**
 * mencari kesulitan paling kecil di tiap kelompok
 */
long long dfs(long long start) {
    visited[start] = true;
    long long k = a[start]; // init kesulitan start (dirinya sendiri)
    for (auto child : adj[start]) {
        if (!visited[child]) {
            long long biaya_child = dfs(child);
            k = min(k, biaya_child);
        }
    }
    return k;
}

int main() {
    // input
    long long n, m, k;
    cin >> n >> m >> k;
    a.resize(n + 1);
    b.resize(m);
    adj.resize(n + 1);
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 0; i < m; i++) cin >> b[i];
    while (k--) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.resize(n + 1);
    for (long long i = 1; i <= n; i++) visited[i] = false;

    for (long long i = 1; i <= n; i++) {
        if (!visited[i]) {
            long long x = dfs(i);
            kesulitan.push_back(x);
        }
    }
    sort(kesulitan.begin(), kesulitan.end(), greater<long long>());
    sort(b.begin(), b.end());
    if (kesulitan.size() > b.size())
        cout << -1 << endl;
    else {
        long long biaya = 0;
        for (long long i = 0; i < kesulitan.size(); i++) {
            long long p = kesulitan[i];
            long long q = b[i];
            biaya += p * q;
        }
        cout << endl << biaya << endl;
    }
    return 0;
}
