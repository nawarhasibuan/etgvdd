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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // ada jalan dari desa n ke desa n+1
    if (a[n - 1] == 0) {
        // semua desa dikunjungi secara berurutan
        for (int i = 0; i < n + 1; i++) {
            cout << i + 1 << ' ';
        }
        cout << endl;
        return;
        // ada jalan dari desa n+1 ke desa 1
    } else if (a[0] == 1) {
        // semua desa dikunjungi secara berurutan kecuali desa terakhir dikunjungi pertama
        cout << n + 1 << ' ';
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ' ';
        }
        cout << endl;
        return;
    } else {
        // periksa apakah ada desa i, dimana a[i] == 0 dan a[i+1] == 1
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 0 && a[i + 1] == 1) {
                // ada desa i, dimana a[i] == 0 dan a[i+1] == 1
                for (int j = 0; j <= i; j++) {
                    cout << j + 1 << ' ';
                }
                cout << n + 1 << ' ';
                for (int j = i + 1; j < n; j++) {
                    cout << j + 1 << ' ';
                }
                cout << endl;
                return;
            }
        }
        // tidak dapat dikunjungi semua desa tepat sekali
        cout << -1 << endl;
    }
}
