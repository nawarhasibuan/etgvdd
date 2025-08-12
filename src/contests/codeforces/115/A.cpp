#include <bits/stdc++.h>

using namespace std;

int depth_employe(int employee, const vector<int> &manager, vector<int> &memo) {
    if (memo[employee] != -1) { // sudah dihitung sebelumnya
        return memo[employee];
    }
    int superior = manager[employee];
    memo[employee] = 1 + depth_employe(superior, manager, memo);
    return memo[employee];
}

int main() {
    // input
    int n;
    cin >> n;
    vector<int> manager(n);
    vector<int> depth(n, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            x = 0;        // convert -1 to 0 for root employee
            depth[i] = 0; // inisiasi depth root
        }
        manager[i] = x - 1; // convert to 0-based index
    }

    // hitung kedalaman setiap karyawan
    for (int i = 0; i < n; i++) {
        if (depth[i] == -1) { // hitung jika depth belum diketahui
            depth[i] = depth_employe(i, manager, depth);
        }
    }

    // output

    cout << *max_element(depth.begin(), depth.end()) + 1 << endl;

    return 0;
}
