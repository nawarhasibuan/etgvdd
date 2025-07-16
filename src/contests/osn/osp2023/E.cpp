#include <iostream>
#include <vector>

using namespace std;

int main() {
    // input
    int m, n;
    cin >> m >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
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
