#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
void solve();

int main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    // input
    int n;
    cin >> n;
    // a1 = a[i-1], b1 = b[i-1]
    long long a1 = 0, b1 = 0;
    // a2 = a[i], b2 = b[i]
    long long a2 = 1, b2 = 1; // basis
    // algoritma
    for (int i = 1; i < n; i++) {
        a1 = a2;
        b1 = b2;
        a2 = (2 * a1 + b1) % MOD;
        b2 = (a1 + 4 * b1) % MOD;
    }
    // output

    cout << (a2 + b2) % MOD << endl;
}
