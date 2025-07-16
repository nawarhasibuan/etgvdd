#include <iostream>
#include <vector>

using namespace std;

int main() {
    // input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> e;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        e.at(u).push_back(v);
        e.at(v).push_back(u);
    }

    // algoritma

    // output

    cout << 0 << endl;

    return 0;
}
