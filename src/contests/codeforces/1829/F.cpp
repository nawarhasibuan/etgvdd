#include <bits/stdc++.h>

using namespace std;

void solve();

int main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    // input
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n + 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // algoritma
    // 1. hitung derajat setiap vertex
    // graph[i] == semua tetangga vertex i. derajat[i] -> size dari graph[i]
    vector<int> degree(n + 1);
    for (int i = 1; i < n + 1; i++) {
        degree[i] = graph[i].size();
    }
    // 2. banyak yang derajat 1 -> x*y
    // 3. banyak yang berderajat berikutnya -> x
    // cara hitung:
    // - sort degree
    sort(degree.begin() + 1, degree.end());
    // degree[1] = 1
    // degree.back(), yang derajat terbesar
    // 4. hitung berderajat 1
    auto itr1 = upper_bound(degree.begin() + 1, degree.end(), 1); // itr adalah idx pertama yang bukan 1
    int xy = itr1 - (degree.begin() + 1);
    int x = 0, y = 0;
    auto itr2 = upper_bound(itr1, degree.end(), *itr1); // mencari banyak berderajat lainnya
    if (itr2 - itr1 == 1) {                             // banyak yang berderajat *itr1 hanya 1.
        x = *itr1;
    } else {
        x = degree.back();
    }
    y = xy / x;
    // output
    cout << x << ' ' << y << '\n';
}
