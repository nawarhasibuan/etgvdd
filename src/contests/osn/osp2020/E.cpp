#include <bits/stdc++.h>
using namespace std;

// n: banyak pasien
// s: banyak jenis virus
// p: pasien terinfeksi langsung
int n, s, p;
vector<int> inap;
vector<pair<string, int>> direct_infected; //{{A,1},{A,2},{B,3},{B,4}}
vector<vector<int>> graph;
vector<int> memo_keganasan;
int keganasan(int v);
/**
 * maximal total lama menginap pada jalur penularan yang dimulai dari start
 */
int dfs(int start) {
    int max_ganas = 0;
    for (auto ditulari : graph[start]) {
        max_ganas = max(dfs(ditulari), max_ganas);
    }
    return max_ganas + inap[start - 1];
}

int main() {
    // input
    cin >> n >> s >> p;
    graph.resize(n + 1);
    memo_keganasan.resize(p + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inap.push_back(x);
    }
    for (int i = 0; i < p; i++) {
        string v;
        int x;
        cin >> v >> x;
        direct_infected.push_back({v, x});
    }
    for (int i = 0; i < n - p; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }

    // algo
    int max_inf = 0;
    string virus;
    for (auto inf : direct_infected) {
        // inf.first -> nama virus
        // inf.second -> yang terinfeksi pertama
        int keganasan_curr = dfs(inf.second);
        if (keganasan_curr > max_inf) {
            max_inf = keganasan_curr;
            virus = inf.first;
        }
    }
    // output
    cout << virus << endl << max_inf << endl;
}
int keganasan(int v) {
    // sudah dihitung
    if (memo_keganasan[v] != 0) return memo_keganasan[v];
    memo_keganasan[v] = inap[v - 1]; // base
    for (int child : graph[v]) {
        memo_keganasan[v] = max(keganasan(child) + inap[v - 1], memo_keganasan[v]);
    }
    return memo_keganasan[v];
}
