#include <bits/stdc++.h>
using namespace std;

// hitung bawahan si x
// bawahan si x = jumlah semua bawahan tetangganya + jumlah tetangga
// bawahan --> bawahan + dirinya
int dfs(vector<vector<int>> &adj, vector<int> &bawahan, int x) {
    // sudah dihitung
    if (bawahan[x] > 0)
        return bawahan[x];
    for (int bwh : adj[x]) {
        bawahan[x] += dfs(adj, bawahan, bwh);
    }
    // basis jika adj[x] kosong
    bawahan[x]++;
    return bawahan[x];
}
/**
 * target jumlah n
 * mata dadu pertama yang muncul (optional)
 * - 1: hitung target = n - 1. dp(n -1)
 * - 2: hitung target --> n - 2. dp(n - 2)
 *
 * dp(n) = dp(n -1)+ dp(n -2) + dp(n - 3) + ...
 * basis: dp(n<= 0) = 0; dp(1) = 1
 *
 * dp(n) --> hitung kemungkinan untuk target n
 *  */

int main() {
    int n;
    cin >> n;
    int x = 1 < 5; // 2^5
    //  010
    //  010 : 1 < 1
    // r 010
    bool hidup = x ^ (1 < n);
    vector<vector<int>> adj(n);
    vector<int> bawahan(n, 0);

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        adj[x - 1].push_back(i);
    }
    dfs(adj, bawahan, 1);
    for (int i = 1; i < n; i++) {
        cout << bawahan[i] - 1 << endl;
    }
    return 0;
}